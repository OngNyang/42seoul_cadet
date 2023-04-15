/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:43:19 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/15 12:47:29 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//각종 에러 및 예외 처리 할 것, 빌트인 안이 아니면 execute실행하도록 함수 하나 더 추가

static char	*get_path(char **inputs, t_setting **set, char **e_path)
{
	int		i;
	char	*exec;

	i = 0;
	while (e_path[i])
	{
		exec = ft_strjoin(e_path[i], "/");
		exec = ft_strjoin(exec, inputs[0]);
		if (access(exec, X_OK) == 0)
			break ;
		free(exec);
		exec = NULL;
		i++;
	}
	return (exec);
}

static void	free_e_path(char **e_path)
{
	int	i;

	i = 0;
	while (e_path[i])
	{
		free(e_path[i]);
		i++;
	}
	free(e_path);
}

static int	isexecute(char **inputs, t_setting **set)
{
	char	*path;
	char	**e_path;
	char	*exec;

	path = get_env_value((*set)->env_list, "PATH");
	if (!path)
		return (-1);
	e_path = ft_split(path, ':');
	exec = get_path(inputs, set, e_path);
	if (exec == NULL)
		return (-1);
	free(path);
	path = inputs[0];
	inputs[0] = ft_strdup(exec);
	free(path);
	execve(exec, inputs, (*set)->envp);
	free(exec);
	perror("execve");
	return (0);
}





int	check_redirection(char *o))
{
	if (ft_strcmp(o, "|") == 0)
		return (2);
	else if (ft_strcmp(o, "<") == 0)
		return (3);
	else if (ft_strcmp(o, ">") == 0)
		return (4);
	else if (ft_strcmp(o, "<<") == 0)
		return (5);
	else if (ft_strcmp(o, ">>") == 0)
		return (6);
	return (0);
}

int	redir_infile(char *filename, ----)
{
	int	fd_in;

	fd_in = open(filename, O_RDONLY);
	dup2(fd_in, STDIN);
	
}

int	go_redirection(inputs, set, &i)
{
	int		flag;
	char	*o;

	o = inputs[*i];
	if (ft_strcmp(o, "|") == 0)
		flag = 
	else if (ft_strcmp(o, "<") == 0)
		flag = redir_infile(----);
	else if (ft_strcmp(o, ">") == 0)
		flag = 
	else if (ft_strcmp(o, "<<") == 0)
		flag = 
	else if (ft_strcmp(o, ">>") == 0)
		flag = 

}

int	execute(char **inputs, t_setting **set)
{
	int		i;
	int		flag;
	char	*o;

	i = 0;
	while (inputs[i])
	{
		flag = 0;
		o = inputs[i];
		if (o == NULL)
			return (1);
		if (check_redirection(o))
			flag = go_redirection(inputs, set, &i)
		else if (execute_check(o))
			flag = go_execute(inputs, set, o);
		// else if (ft_strcmp(o, "|") == 0)
		// 	flag = function_about_pipe_should_be_come();
		// else if (ft_strcmp(o, "<<") == 0)
		// 	heredoc_function_should_be_come();
		else
			isexecute(inputs, set);
		i++;
	}
	return (flag);
}



/*
original execute()
*/
// int	execute(char **inputs, t_setting **set)
// {
// 	char	*o;
// 	int		flag;

// 	flag = 0;
// 	o = inputs[0];
// 	if (o == NULL)
// 		return (1);
// 	if (execute_check(o))
// 		flag = go_execute(inputs, set, o);
// 	else
// 		isexecute(inputs, set);
// 	return (flag);
// }
