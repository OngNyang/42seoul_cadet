/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:29:16 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/29 16:13:47 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>

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

void	child_process(int *pipe_fd, char **argv, char **envp);
void	parent_process(int *pipe_fd, char **argv, char **envp);

char	**tokenize(char **envp);
char	*free_and_return(char **token_env_path, char *buffer);

#endif