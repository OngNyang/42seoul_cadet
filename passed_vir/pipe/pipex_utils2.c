/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:26:49 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/29 16:13:08 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
