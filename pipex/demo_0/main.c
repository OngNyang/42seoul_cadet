#include "pipex.h"

#include <fcntl.h>

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_p_error(t_bool bool)
{
	if (bool == TRUE)
		ft_printf("wrong arguments\n");
	exit(0);
}

int	open_file(char *file, t_io io)
{
	int	fd;

	if (io == INPUT)
		fd = open(file, O_RDONLY, 0777);
	else if (io == OUTPUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);	//없으면 생성, 기존 파일 내용 모두 삭제
	if (fd == -1)				//open() 실패시
		exit(1);
	return (fd);
}


/*
envp 중에 PATH를 찾는구나
*/
char	*my_getenv(char *name, char **envp)
{
	int	i;
	int	j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')		// \0 또는 = 을 찾을때까지 j인덱스 증가
			j++;
		sub = ft_substr(envp[i], 0, j);				// \0 또는 = 전까지 문자열 복사
		if (ft_strncmp(sub, name, j) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", envp), ':');	//PATH 다음부터 : 단위로 잘라서 이차원 배열에 저장
	s_cmd = ft_split(cmd, ' ');		// 명령어를 띄어쓰기 단위로 잘라서 이차원 배열에 저장
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");	//각각의 끝에 / 붙여줌
		exec = ft_strjoin(path_part, s_cmd[0]);	//path 랑 명령어 붙여줌. bin/ls 이런식으로
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)		//파일 존재여부, 실행 권한 여부.....F_OK없어도 되는거 아님?
		{
			ft_free_tab(s_cmd);
			return (exec);					//실행 가능하면 반환
		}
		free(exec);
	}
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	return (cmd);
}


void	exec(char *cmd, char **envp)
{
	char	**splited_cmd;
	char	*path;

	splited_cmd = ft_split(cmd, ' ');		//뛰어쓰기로 구분해서 저장 -> 옵션을 구분하기 위해서
	path = get_path(splited_cmd[0], envp);	//명령어 원형을 넣어줌, 경로와 / 명령어를 붙인 문자열이 반환됨
	if (execve(path, splited_cmd, envp) == -1)		//실행을 하는데, 실패할경우 아래와 같이 해라
	{
		ft_printf("pipex: command not found: ");
		ft_putendl_fd(splited_cmd[0], 2);
		ft_free_tab(splited_cmd);
		exit(1);
	}
}

void	child(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open_file(argv[1], INPUT);
	dup2(fd, STDIN);						//fd변수를 0번 파일디스크립터에 복사. 즉 표준 입력을 해당 파일로 redirect
	dup2(p_fd[OUTPUT], STDOUT);
	close(p_fd[INPUT]);
	exec(argv[CMD1], envp);			//첫번째 명령어 
}

void	parent(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open_file(argv[FILE2], OUTPUT);
	dup2(fd, STDOUT);
	dup2(p_fd[INPUT], STDIN);
	close(p_fd[OUTPUT]);
	exec(argv[CMD2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		ft_p_error(TRUE);
	if (pipe(p_fd) == -1)	//두개의 fd 연결.
		exit(1);
	pid = fork();			//자식 프로세스 생성
	if (pid == -1)
		exit(1);
	if (pid == 0)			//자식 프로세스이면
		child(argv, p_fd, envp);
	parent(argv, p_fd, envp);
}