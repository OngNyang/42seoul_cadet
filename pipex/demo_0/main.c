#include "pipex.h"

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