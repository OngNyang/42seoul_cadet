/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:29:42 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/29 13:02:06 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
		ft_p_error("Error: need 5 arguments");
	if (pipe(pipe_fd) == -1)
		ft_p_error("Error: failure in pipe() function");
	pid = fork();
	if (pid < 0)
		ft_p_error("Error: failure in fork() function");
	else if (pid == 0)
	{
		child_process(pipe_fd, argv, envp);
	}
	else
	{
		parent_process(pipe_fd, argv, envp);
	}
}
