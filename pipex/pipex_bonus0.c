#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

void	make_arr_pipe(int **arr_pipe, int argc)
{
	int	i;

	arr_pipe = malloc(sizeof(int *) * (argc - 4 + 1));
	arr_pipe[argc -4] = NULL;
	i = 0;
	while (arr_pipe[i])
	{
		arr_pipe[i] = malloc(sizeof(int) * 2);
		i++;
	}
}


void	fork_proces(int argc, char **argv, char **envp, int **arr_pipe, int i)
{
	pid_t	pid;
	int		fd_out;
	int		fd_in;
	
	if (pipe(arr_pipe[i]))
		exit(1);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		if (arr_pipe[i+1] == NULL)
		{
			fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd_out, 1);
		}
		else
			dup2(arr_pipe[i + 1][1], 1);
		dup2(arr_pipe[i][0], 0);
		exec(------);
	}
	else
	{
		fd_in = open(argv[1], O_RDONLY);
		dup2(fd, 0);
		dup2(arr_pipe[i][1], 1);
		exec(-----);
		wait();
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd_in;
	int	fd_out;
	int	i;
	int	**arr_pipe;

	if (argc < 5)
		exit(1);
	arr_pipe = malloc(sizeof(int *) * (argc - 4 + 1));


	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		exit(1);
	// fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// if (fd_out == -1)
	// 	exit(1);
	if (dup2(fd_in, 0) == -1)
		exit(1);
	i = 0;
	while (i < argv - 4)
	{
		// fork_process(argv[i + 2], envp, arr_pipe[i]);
		fork_proces(argv, envp, arr_pipe, i);
		i++;
	}
	dup2(fd_out, 1);
	exec(-----);
}