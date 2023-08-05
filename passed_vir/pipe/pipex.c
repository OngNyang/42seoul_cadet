/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:31:31 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/28 14:30:03 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *pipe_fd, char **argv, char **envp)
{
	int		fd;
	char	*cmd_with_path;
	char	**cmd_args;

	close(pipe_fd[READ]);
	fd = open(argv[FILE1], O_RDONLY);
	if (fd == -1)
		ft_p_error("Error: failure in open()");
	if (dup2(fd, STDIN) == -1)
		ft_p_error("Error: dup2()");
	if (dup2(pipe_fd[WRITE], STDOUT) == -1)
		ft_p_error("Error: dup2()");
	cmd_args = ft_split(argv[CMD1], ' ');
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		free_2d_array(cmd_args);
		free(cmd_with_path);
		ft_p_error("Error: failure in execve()");
	}
}

void	parent_process(int *pipe_fd, char **argv, char **envp)
{
	int		fd;
	char	*cmd_with_path;
	char	**cmd_args;

	close(pipe_fd[WRITE]);
	fd = open(argv[FILE2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_p_error("Error: failure in open()");
	if (dup2(fd, STDOUT) == -1)
		ft_p_error("Error: dup2()");
	if (dup2(pipe_fd[READ], STDIN) == -1)
		ft_p_error("Error: dup2()");
	cmd_args = ft_split(argv[CMD2], ' ');
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		free_2d_array(cmd_args);
		free(cmd_with_path);
		ft_p_error("Error: failure in execve()");
	}
}
