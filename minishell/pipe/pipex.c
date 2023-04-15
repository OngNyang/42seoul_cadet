#include "pipex.h"
#include <stdio.h>

/*
exit(1) 으로 일괄 처리했음. 추후 제작한 함수로 대체하기.
*/

int	**create_pipes(int num_pipe)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * num_pipe);
	i = 0;
	while (i < num_pipe)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < num_pipe)
	{
		if (pipe(pipes[i]) == -1)
			exit(1);
		i++;
	}
	return (pipes);
}

void	first_process(int num_pipe, int **pipes, char **argv, char **envp)
{
	int	j;
	int	k;
	int	fd_in;

	j = 0;
	while (j < num_pipe)
	{
		k = 0;
		while (k < 2)
		{
			if (!(j == 0 && k == 1))
				close(pipes[j][k]);
			k++;
		}
		j++;
	}
	fd_in = open(argv[1], O_RDONLY);
	dup2(fd_in, STDIN);
	dup2(pipes[0][WRITE], STDOUT);
	split_exec(argv[2], envp);
}

void	last_process(int num_pipe, int **pipes, char **argv, char **envp)
{
	int	j;
	int	k;
	int	fd_out;
	int	argc;

	argc = num_pipe + 4;
	j = 0;
	while (j < num_pipe)
	{
		k = 0;
		while (k < 2)
		{
			if (!(j == num_pipe - 1 && k == 0))
				close(pipes[j][k]);
			k++;
		}
		j++;
	}
	fd_out = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd_out, STDOUT);
	dup2(pipes[num_pipe -1][READ], STDIN);
	split_exec(argv[argc - 2], envp);
}

void	middle_process(int num_pipe, int **pipes, char **argv, char **envp, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < num_pipe)
	{
		k = 0;
		while (k < 2)
		{
			if (!((j == i-1 && k == 0) || (j == i && k == 1)))
				close(pipes[j][k]);
			k++;
		}
		j++;
	}
	dup2(pipes[i][1], STDOUT);
	dup2(pipes[i-1][0], STDIN);
	split_exec(argv[i + 2], envp);
}




void	fork_process(int num_child, int num_pipe, int **pipes, char **argv, char **envp)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < num_child)
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		else if (pid == 0)
		{
			if (i == 0)
				first_process(num_pipe, pipes, argv, envp);
			else if (i == num_pipe)
				last_process(num_pipe, pipes, argv, envp);
			else
				middle_process(num_pipe, pipes, argv, envp, i);
		}
		i++;
	}
}

void	close_pipes(int num_pipe, int **pipes)
{
	int	i;

	i = 0;
	while (i < num_pipe)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	wait_child(int num_child)
{
	int	i;

	i = 0;
	while (i < num_child)
	{
		wait(NULL);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		num_pipe;
	int		num_child;
	int		**pipes;
	pid_t	pid;

	num_pipe = argc - 4;
	num_child = argc - 3;
	pipes = create_pipes(num_pipe);
	fork_process(num_child, num_pipe, pipes, argv, envp);
	close_pipes(num_pipe, pipes);
	return (0);
}

/*
	// for(int i=0; i<num_pipe; i++)
	// {
	// 	for (int j=0; j<2; j++)
	// 	{
	// 		printf(" %d ", pipes[i][j]);
	// 	}
	// 	printf("\n");
	// }
*/

// int	main(int argc, char **argv, char **envp)
// {
// 	int	num_pipes = argc -4;
// 	int	num_child = argc -3;
// 	int	pipes[num_pipes][2];
// 	pid_t	pid;

// 	for (int i=0; i<num_pipes; i++)
// 	{
// 		if (pipe(pipes[i]) == -1)
// 		{
// 			perror("pipe");
// 			exit(EXIT_FAILURE);
// 		}
// 	}

// 	for (int i=0; i<num_child; i++)
// 	{
// 		pid = fork();
// 		if (pid == -1)
// 		{
// 			perror("fork");
// 			exit(EXIT_FAILURE);
// 		}
// 		else if (pid == 0)
// 		{
// 			if (i == 0)
// 			{
// 				// close(pipes[0][READ]);

// 				for (int j=0; j<num_pipes; j++)
// 				{
// 					for (int k=0; k<2; k++)
// 					{
// 						if (!(j == 0 && k == 1))
// 							close(pipes[j][k]);
// 					}
// 				}


// 				int	fd_in = open(argv[1], O_RDONLY);
// 				dup2(fd_in, STDIN);
// 				dup2(pipes[0][WRITE], STDOUT);
// 				split_exec(argv[2], envp);
// 			}
// 			else if (i == num_pipes)
// 			{
// 				// close(pipes[0][WRITE]);

// 				for (int j=0; j<num_pipes; j++)
// 				{
// 					for (int k=0; k<2; k++)
// 					{
// 						if (!(j == num_pipes-1 && k == 0))
// 							close(pipes[j][k]);
// 					}
// 				}

// 				int fd_out = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 				dup2(fd_out, STDOUT);
// 				dup2(pipes[num_pipes -1][READ], STDIN);
// 				split_exec(argv[argc - 2], envp);
// 			}
// 			else					//중간 파이프
// 			{
// 				for (int j=0; j<num_pipes; j++)
// 				{
// 					for (int k=0; k<2; k++)
// 					{
// 						if (!((j == i-1 && k == 0) || (j == i && k == 1)))
// 							close(pipes[j][k]);
// 					}
// 				}
// 				dup2(pipes[i][1], STDOUT);
// 				dup2(pipes[i-1][0], STDIN);
// 				split_exec(argv[i + 2], envp);
// 			}
// 		}
// 	}
// 	for(int i=0; i<num_pipes; i++)
// 	{
// 		close(pipes[i][0]);
// 		close(pipes[i][1]);
// 	}
// 	for(int i=0; i<num_child; i++)
// 	{
// 		wait(NULL);
// 	}
// 	return (0);
// }