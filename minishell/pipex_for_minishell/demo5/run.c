#include "pipex.h"

void	unlink_temp_file(t_heredoc *hdoc)
{
	int	i;

	i = 0;
	while (hdoc->filename_temp[i])
	{
		unlink(hdoc->filename_temp[i]);
		i++;
	}
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

t_info	*init_info(t_deque *deque)
{
	t_info	*info;

	info = malloc(sizeof(t_info) * 1);
	info->num_pipe = deque_size(deque) - 1;
	info->pipes = create_pipes(info->num_pipe);
	info->arr_pid = malloc(sizeof(pid_t) * (info->num_pipe + 1));
	return (info);
}

t_deque	*parsing_pipe(char **arg)
{
	int		i;
	t_deque	*deque;
	t_node	*node;

	deque = new_deque();
	node = push_init_new_node(deque);
	i = 0;
	while (arg[i])
	{
		if ((ft_strcmp(arg[i], "<") == 0) || (ft_strcmp(arg[i], ">") == 0) || (ft_strcmp(arg[i], "<<") == 0) || (ft_strcmp(arg[i], ">>") == 0))
		{
			node->file_redir = append_str(node->file_redir, arg[i+1]);
			node->order_redir = append_str(node->order_redir, arg[i]);
			i += 2;
		}
		else if (ft_strcmp(arg[i], "|") == 0)
		{
			node = push_init_new_node(deque);
			i += 1;
		}
		else	//커맨드인 경우
			node->cmd = append_str(node->cmd, arg[i++]);
	}
	return (deque);
}


void	run_cmd(char **arg, char **envp)
{
	t_deque		*deque;
	t_info		*info;
	t_node		*node;
	t_heredoc	*hdoc;

	deque = parsing_pipe(arg);
	info = init_info(deque);
	hdoc = do_heredoc(arg, deque);
	node = deque->front;
	while (node)
	{
		info->arr_pid[node->idx] = fork();
		if (info->arr_pid[node->idx] < 0)
			ft_p_error("Error: fork()");
		else if (info->arr_pid[node->idx] == 0)
			child_process(node, info, envp);
		else
			node = parent_process(node, info);
	}
	ft_wait_pids(info);
	unlink_temp_file(hdoc);
}

