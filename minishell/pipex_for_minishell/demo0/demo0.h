#ifndef	DEMO0_H
# define DEMO0_H

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

typedef struct	s_redir_flag
{
	t_bool	infile;
	t_bool	outfile_overwrite;
	t_bool	outfile_append;
	t_bool	here_doc;
}				t_redir_flag;

typedef struct	s_info
{
	struct s_redir_flag	redir_flag;
	int					num_pipe;
	int					num_process;
	int					**pipes;
	int					idx_prcs;
	int					idx_arg;
	char				**arg;
	char				**envp;
}				t_info;



typedef struct	s_deque
{
	struct s_node	*front;
	struct s_node	*rear;
}				t_deque;

typedef struct	s_node
{
	char			**cmd;
	char			**infile;
	char			**outfile_ow;
	char			**outfile_apd;
	char			**here_doc;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;


// char	*free_and_return(char **token_env_path, char *buffer);
// char	*find_env_path(char **envp);
// char	*find_command_path(char *cmd, char **envp);
// char	**tokenize(char **envp);
// void	split_exec(char *cmd_with_option, char **envp);
// void	free_2d_array(char **arr);
// void	ft_p_error(char *str);
int		**create_pipes(int num_pipe);
int		ft_strcmp(const char *s1, const char *s2);


void	init_redir_flag(t_redir_flag *flag);
void	init_info(t_info *info, char **arg_s, char **envp_orig);
void	first_process(t_info *info);
void	fork_process(t_info *info);



#endif
