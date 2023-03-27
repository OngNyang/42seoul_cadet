/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:56 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/24 00:05:13 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_read_err(char **buffer, char **stt_buffer);
size_t	gnl_ft_strlen(const char *str);
char	*gnl_ft_strchr(const char *s, int c);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif