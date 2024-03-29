
#ifndef	PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

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

char	*free_and_return(char **token_env_path, char *buffer);
char	*find_env_path(char **envp);
char	*find_command_path(char *cmd, char **envp);
char	**tokenize(char **envp);
void	split_exec(char *cmd_with_option, char **envp);
void	free_2d_array(char **arr);
void	ft_p_error(char *str);



#endif