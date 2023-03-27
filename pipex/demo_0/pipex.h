#ifndef	PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef enum e_io
{
	INPUT = 0,
	OUTPUT = 1
}				t_io;

typedef enum e_rw
{
	READ = 0,
	WRITE = 1
}			t_rw;

typedef enum e_stdio
{
	STDIN = 0,
	STDOUT = 1
}				t_stdio;

typedef enum e_argv
{
	FILE1 = 1,
	CMD1 = 2,
	CMD2 = 3,
	FILE2 = 4
}			t_argv;

void	ft_p_error(char *str);
void	free_2d_array(char **arr);
char	*find_env_path(char **envp);
char	*find_command_path(char *cmd, char **envp);
void	exec_cmd(char *cmd_with_option, char **envp);

void	child_process(int *pipe_fd, char **argv, char **envp);
void	parent_process(int *pipe_fd, char **argv, char **envp);

#endif