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


















#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PIPES 3

int main()
{
    int pipes[NUM_PIPES][2];
    pid_t pid;

    // Create the pipes
    for(int i=0; i<NUM_PIPES; i++)
    {
        if(pipe(pipes[i]) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
    }

    // Create the child processes
    for(int i=0; i<NUM_PIPES+1; i++)
    {
        pid = fork();
        if(pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if(pid == 0) // child process
        {
            // Close unused pipes
            if(i == 0)
            {
                close(pipes[0][0]);
                close(pipes[NUM_PIPES-1][1]);
                for(int j=1; j<NUM_PIPES; j++)
                {
                    close(pipes[j][0]);
                    close(pipes[j][1]);
                }
            }
            else if(i == NUM_PIPES)
            {
                close(pipes[NUM_PIPES-1][1]);
                close(pipes[0][0]);
                for(int j=0; j<NUM_PIPES-1; j++)
                {
                    close(pipes[j][0]);
                    close(pipes[j][1]);
                }
            }
            else
            {
                close(pipes[i-1][1]);
                close(pipes[i][0]);
                for(int j=0; j<NUM_PIPES; j++)
                {
                    if(j != i-1 && j != i)
                    {
                        close(pipes[j][0]);
                        close(pipes[j][1]);
                    }
                }
            }

            // Redirect stdin and stdout to the appropriate pipes
            if(i == 0)
            {
                dup2(pipes[0][1], STDOUT_FILENO);
            }
            else if(i == NUM_PIPES)
            {
                dup2(pipes[NUM_PIPES-1][0], STDIN_FILENO);
            }
            else
            {
                dup2(pipes[i-1][0], STDIN_FILENO);
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            // Execute the command
            execlp("ls", "ls", NULL);
            exit(EXIT_SUCCESS);
        }
    }

    // Close all pipes in the parent process
    for(int i=0; i<NUM_PIPES; i++)
    {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    // Wait for all child processes to exit
    for(int i=0; i<NUM_PIPES+1; i++)
    {
        wait(NULL);
    }

    return 0;
}
