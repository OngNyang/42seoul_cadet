
/*
main함수
	if (인자가 5개 이상이어야함)
	if (here doc 처리)
	dup2(입력파일, STDIN)
	dup2(출력파일, STDOUT)
	while (인자수 -4 만큼)
	{
		fork() 로 프로세스 생성
		dup2() 로 프로세스의 입출력 방향 바꿔주기
	}


here_doc함수


*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

void	fork_process(char *argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)	//child
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		exec(----);
	}
	else			//parent
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		waitpid(pid, NULL, 0);
	}
}



int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
		exit(1);

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		exit(1);
	fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		exit(1);
	if (dup2(fd_in, 0) == -1)
		exit(1);
	i = 0;
	while (i < argv - 4)
	{
		fork_process(argv[i + 2], envp);
		i++;
	}
	dup2(fd_out, 1);
	exec(-----);
}