#include "pipex.h"

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
	exec_cmd(argv[CMD1], envp);
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
	exec_cmd(argv[CMD2], envp);
}