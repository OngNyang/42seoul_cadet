#include "mini_pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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

void	init_redir_flag(t_redir_flag *flag)
{
	flag->infile = FALSE;
	flag->outfile_overwrite = FALSE;
	flag->outfile_append = FALSE;
	flag->here_doc = FALSE;
}


void	init_info(t_info *info, char **arg_s, char **envp_orig)
{
	int	i;

	init_redir_flag(&(info->redir_flag));
	info->num_pipe = 0;
	i = 0;
	while (arg_s[i])
	{
		if (ft_strcmp(arg_s[i], "|") == 0)
			info->num_pipe++;
		else if (ft_strcmp(arg_s[i], "<") == 0)
			info->redir_flag.infile = TRUE;
		else if (ft_strcmp(arg_s[i], ">") == 0)
			info->redir_flag.outfile_overwrite = TRUE;
		else if (ft_strcmp(arg_s[i], ">>") == 0)
			info->redir_flag.outfile_append = TRUE;
		else if (ft_strcmp(arg_s[i], "<<") == 0)
			info->redir_flag.here_doc = TRUE;
		i++;
	}
	info->num_process = info->num_pipe + 1;
	info->arg = arg_s;
	info->idx_prcs = 0;
	info->idx_arg = 0;
	info->pipes = create_pipes(info->num_pipe);
	info->envp = envp_orig;
}



// void	redir_infile(char *filename)
// {
// 	int	fd_in;

// 	fd_in =  open(filename, O_RDONLY);
// 	dup2(fd_in, STDIN);
// }




