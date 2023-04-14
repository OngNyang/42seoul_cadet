


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "pipex.h"
#include "./libft/libft.h"

// #define num_pipes 3


void	ft_p_error(char *str)
{
	printf("%s\n", str);
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

char	*find_command_path(char *cmd, char **envp)
{
	char	**token_env_path;
	char	*buffer;
	char	*temp;
	int		j;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	token_env_path = tokenize(envp);
	j = 0;
	while (token_env_path[j])
	{
		buffer = ft_strjoin(token_env_path[j], "/");
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

char	**tokenize(char **envp)
{
	char	*env_path;
	char	**token_env_path;

	env_path = find_env_path(envp);
	token_env_path = ft_split(env_path, ':');
	return (token_env_path);
}

char	*free_and_return(char **token_env_path, char *buffer)
{
	free_2d_array(token_env_path);
	return (buffer);
}


void	split_exec(char *cmd_with_option, char **envp)
{
	char	*cmd_with_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd_with_option, ' ');
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		ft_p_error("Error: failure in execve()");
	}
}




// int main(int argc, char **argv, char **envp)
// {
// 	int	 num_pipes = argc -4;
// 	int pipes[num_pipes][2];
// 	pid_t pid;

// 	// Create the pipes
// 	for(int i=0; i<num_pipes; i++)
// 	{
// 		if(pipe(pipes[i]) == -1)
// 		{
// 			perror("pipe");
// 			exit(EXIT_FAILURE);
// 		}
// 	}

// 	// Create the child processes
// 	for(int i=0; i<num_pipes+1; i++)
// 	{
// 		pid = fork();
// 		if(pid == -1)
// 		{
// 			perror("fork");
// 			exit(EXIT_FAILURE);
// 		}
// 		else if(pid == 0) // child process
// 		{
// 			// Close unused pipes
// 			if(i == 0)
// 			{
// 				close(pipes[0][0]);
// 				// close(pipes[num_pipes-1][1]);
// 				close(pipes[num_pipes][1]);
// 				for(int j=1; j<num_pipes; j++)
// 				{
// 					close(pipes[j][0]);
// 					close(pipes[j][1]);
// 				}
// 			}
// 			else if(i == num_pipes)
// 			{
// 				close(pipes[num_pipes-1][1]);
// 				close(pipes[0][0]);
// 				for(int j=0; j<num_pipes-1; j++)
// 				{
// 					close(pipes[j][0]);
// 					close(pipes[j][1]);
// 				}
// 			}
// 			else
// 			{
// 				close(pipes[i-1][1]);
// 				close(pipes[i][0]);
// 				for(int j=0; j<num_pipes; j++)
// 				{
// 					if(j != i-1 && j != i)
// 					{
// 						close(pipes[j][0]);
// 						close(pipes[j][1]);
// 					}
// 				}
// 			}

// 			// Redirect stdin and stdout to the appropriate pipes
// 			if(i == 0)
// 			{
// 				int	fd_infile = open(argv[1], O_RDONLY);	//1번 인자 읽어서
// 				if (fd_infile == -1)
// 					exit(1);
// 				dup2(fd_infile, STDIN_FILENO);
// 				dup2(pipes[0][1], STDOUT_FILENO);

// 				printf("%s, idx : %d\n", argv[2], i);
// 				split_exec(argv[2], envp);
// 				exit(EXIT_SUCCESS);
// 			}
// 			else if(i == num_pipes)
// 			{
// 				int	fd_outfile = open(argv[argc-1],O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 				if (fd_outfile == -1)
// 					exit(1);
// 				dup2(fd_outfile, STDOUT_FILENO);
// 				dup2(pipes[num_pipes-1][0], STDIN_FILENO);

// 				printf("%s, idx : %d\n", argv[argc - 1], i);
// 				split_exec(argv[argc -1], envp);
// 				exit(EXIT_SUCCESS);
// 			}
// 			else
// 			{
// 				dup2(pipes[i-1][0], STDIN_FILENO);
// 				dup2(pipes[i][1], STDOUT_FILENO);

// 				split_exec(argv[i + 2], envp);
// 				exit(EXIT_SUCCESS);
// 			}

// 			// Execute the command
// 			// execlp("cat", "cat", NULL);

// 			// printf("%s, %d\n", argv[i + 1], i + 2);
// 			// split_exec(argv[i + 1], envp);
// 			// exit(EXIT_SUCCESS);
// 		}
// 	}

// 	// Close all pipes in the parent process
// 	for(int i=0; i<num_pipes; i++)
// 	{
// 		close(pipes[i][0]);
// 		close(pipes[i][1]);
// 	}

// 	// Wait for all child processes to exit
// 	for(int i=0; i<num_pipes+1; i++)
// 	{
// 		wait(NULL);
// 	}

// 	return 0;
// }



// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>

// #define NUM_PIPES 3

// int main()
// {
//     int pipes[NUM_PIPES][2];
//     pid_t pid;

//     // Create the pipes
//     for(int i=0; i<NUM_PIPES; i++)
//     {
//         if(pipe(pipes[i]) == -1)
//         {
//             perror("pipe");
//             exit(EXIT_FAILURE);
//         }
//     }

//     // Create the child processes
//     for(int i=0; i<NUM_PIPES+1; i++)
//     {
//         pid = fork();
//         if(pid == -1)
//         {
//             perror("fork");
//             exit(EXIT_FAILURE);
//         }
//         else if(pid == 0) // child process
//         {
//             // Close unused pipes
//             if(i == 0)
//             {
//                 close(pipes[0][0]);
//                 close(pipes[NUM_PIPES-1][1]);
//                 for(int j=1; j<NUM_PIPES; j++)
//                 {
//                     close(pipes[j][0]);
//                     close(pipes[j][1]);
//                 }
//             }
//             else if(i == NUM_PIPES)
//             {
//                 close(pipes[NUM_PIPES-1][1]);
//                 close(pipes[0][0]);
//                 for(int j=0; j<NUM_PIPES-1; j++)
//                 {
//                     close(pipes[j][0]);
//                     close(pipes[j][1]);
//                 }
//             }
//             else
//             {
//                 close(pipes[i-1][1]);
//                 close(pipes[i][0]);
//                 for(int j=0; j<NUM_PIPES; j++)
//                 {
//                     if(j != i-1 && j != i)
//                     {
//                         close(pipes[j][0]);
//                         close(pipes[j][1]);
//                     }
//                 }
//             }

//             // Redirect stdin and stdout to the appropriate pipes
//             if(i == 0)
//             {
//                 dup2(pipes[0][1], STDOUT_FILENO);
//             }
//             else if(i == NUM_PIPES)
//             {
//                 dup2(pipes[NUM_PIPES-1][0], STDIN_FILENO);
//             }
//             else
//             {
//                 dup2(pipes[i-1][0], STDIN_FILENO);
//                 dup2(pipes[i][1], STDOUT_FILENO);
//             }

//             // Execute the command
//             execlp("ls", "ls", NULL);
//             exit(EXIT_SUCCESS);
//         }
//     }

//     // Close all pipes in the parent process
//     for(int i=0; i<NUM_PIPES; i++)
//     {
//         close(pipes[i][0]);
//         close(pipes[i][1]);
//     }

//     // Wait for all child processes to exit
//     for(int i=0; i<NUM_PIPES+1; i++)
//     {
//         wait(NULL);
//     }

//     return 0;
// }





int	main(int argc, char **argv, char **envp)
{
	int	num_pipes = argc -4;
	int	num_child = argc -3;
	int	pipes[num_pipes][2];
	pid_t	pid;

	for (int i=0; i<num_pipes; i++)
	{
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}

	for (int i=0; i<num_child; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (i == 0)
			{
				close(pipes[0][READ]);
				// for (int j=0; j<num_pipes; j++)
				// {
				// 	for (int k=0; k<2; j++)
				// 	{
				// 		if (!(j == 0 && k == 1))
				// 			close(pipes[j][k]);
				// 	}
				// }


				int	fd_in = open(argv[1], O_RDONLY);
				dup2(fd_in, STDIN);
				dup2(pipes[0][WRITE], STDOUT);
				split_exec(argv[2], envp);
			}
			else if (i == num_pipes)
			{
				close(pipes[0][WRITE]);
				// for (int j=0; j<num_pipes; j++)
				// {
				// 	for (int k=0; k<2; j++)
				// 	{
				// 		if (!(j == num_pipes-1 && k == 0))
				// 			close(pipes[j][k]);
				// 	}
				// }


				int fd_out = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				dup2(fd_out, STDOUT);
				dup2(pipes[num_pipes -1][READ], STDIN);
				split_exec(argv[argc - 2], envp);
			}
			// else					//중간 파이프
			// {
			// 	for (int j=0; j<num_pipes; j++)
			// 	{
			// 		for (int k=0; k<2; j++)
			// 		{
			// 			if (!((j == i-1 && k == 0) || (j == i && k == 1)))
			// 				close(pipes[j][k]);
			// 		}
			// 	}
			// 	dup2()
			// }
		}
	}
	for(int i=0; i<num_pipes; i++)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
	}
	for(int i=0; i<num_child; i++)
	{
		wait(NULL);
	}
	return (0);
}