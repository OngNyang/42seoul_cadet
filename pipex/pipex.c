#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void	ft_p_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_env_path(char **envp)
{
	int		i;
	char	*env_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_path = envp[i] + 5;
			return (env_path);
		}
		i++;
	}
	return (NULL);
}

char	*free_and_return(char **token_env_path, char *buffer)
{
	free_2d_array(token_env_path);
	return (buffer);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	*env_path;
	char	**token_env_path;
	char	*buffer;
	char	*temp;
	int		j;

	env_path = find_env_path(envp);
	token_env_path = ft_split(env_path, ':');		// :을 구분자로 나누어서 문자열 저장.
	j = 0;
	while (token_env_path[j])
	{
		buffer = ft_strjoin(token_env_path[j], "/");			// 마지막에 /붙여줘야함
		temp = buffer;
		buffer = ft_strjoin(temp, cmd);
		free(temp);
		if (access(buffer, F_OK | X_OK) == 0)
			return (free_and_return(token_env_path, buffer));
		else
			free(buffer);
		j++;
	}
	ft_putstr_fd("command not found\n", 2);
	exit(1);
	return (NULL);
}


void	check_leaks(void)
{
	system("leaks pipex");
}

void	exec(char *cmd_with_option, char **envp)
{
/*
2차원 배열 {명령어(경로포함), 옵션, ..., NULL}
*/
	char	*cmd_with_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd_with_option, ' ');
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		free_2d_array(cmd_args);
		free(cmd_with_path);
		ft_p_error("Error: failure in execve()");
	}
}


void	child_process(int *pipe_fd, char **argv, char **envp)
{
/*
- 읽기용 파이프 닫기
- file1열기
- file1을 표준 입력으로
- 쓰기용 파이프를 표준 출력으로
- cmd1실행.
*/
	int	fd;

	close(pipe_fd[READ]);
	fd = open(argv[FILE1], O_RDONLY, 0777);
	if (fd == -1)
		ft_p_error("Error: failure in open()");
	if (dup2(fd, STDIN) == -1)					//표준 입력을 fd로
		ft_p_error("Error: dup2()");
	if (dup2(pipe_fd[WRITE], STDOUT) == -1)		//표준 출력을 파이프의 출력으로
		ft_p_error("Error: dup2()");
	exec(argv[CMD1], envp);
}

void	parent_process(int *pipe_fd, char **argv, char **envp)
{
	int	fd;

	close(pipe_fd[WRITE]);
	fd = open(argv[FILE2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_p_error("Error: failure in open()");
	if (dup2(fd, STDOUT) == -1)		//fd를 stdout으로
		ft_p_error("Error: dup2()");
	if (dup2(pipe_fd[READ], STDIN) == -1)	//pipe[read]를 stdin으로
		ft_p_error("Error: dup2()");
	exec(argv[CMD2], envp);
}

int main(int argc, char **argv, char **envp)
{
	/*
	- 인자 갯수 5개 확인
	- 자식 프로세스 생성
	- 파이프로 연결
	*/
	pid_t	pid;
	int		pipe_fd[2];
	char	write_msg[20] = "hello world!";
	char	read_msg[20];

	if (argc != 5)
		ft_p_error("Error: need 5 arguments");

	if (pipe(pipe_fd) == -1)
		ft_p_error("Error: failure in pipe() function");

	pid = fork();

	if (pid < 0)
		ft_p_error("Error: failure in fork() function");
	else if (pid == 0)		//자식 프로세스는 읽어들임
	{
		child_process(pipe_fd, argv, envp);
	}
	else					//부모 프로세스는 씀.
	{
		parent_process(pipe_fd, argv, envp);
	}
}