/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:24 by hyejeong          #+#    #+#             */
/*   Updated: 2023/02/24 00:05:40 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_post_str(char *stt_buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stt_buffer[i] != '\0' && stt_buffer[i] != '\n')
		i++;
	if (stt_buffer[i] == '\0')
	{
		free(stt_buffer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (gnl_ft_strlen(stt_buffer) - i + 1));
	if (!str)
	{
		free(stt_buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (stt_buffer[i] != '\0')
		str[j++] = stt_buffer[i++];
	str[j] = '\0';
	free(stt_buffer);
	return (str);
}

static char	*ft_get_pre_str(char *stt_buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (stt_buffer[i] == '\0')
		return (ft_read_err(&str, &stt_buffer));
	while (stt_buffer[i] != '\0' && stt_buffer[i] != '\n')
		i++;
	if (stt_buffer[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (stt_buffer[i] != '\0')
	{
		str[i] = stt_buffer[i];
		i++;
		if (stt_buffer[i - 1] == '\n')
			break ;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_strmerge(char *stt_buffer, char *buffer)
{
	char	*str;

	if (!stt_buffer)
	{
		stt_buffer = (char *)malloc(sizeof(char) * 1);
		if (!stt_buffer)
			return (ft_read_err(&buffer, &stt_buffer));
		stt_buffer[0] = '\0';
	}
	str = gnl_ft_strjoin(stt_buffer, buffer);
	if (!str)
	{
		return (ft_read_err(&buffer, &stt_buffer));
	}
	free(stt_buffer);
	return (str);
}

static char	*ft_read(int fd, char *stt_buffer)
{
	char	*buffer;
	int		len;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	len = 1;
	while (!gnl_ft_strchr(stt_buffer, '\n') && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (ft_read_err(&buffer, &stt_buffer));
		buffer[len] = '\0';
		stt_buffer = ft_strmerge(stt_buffer, buffer);
		if (!stt_buffer)
			return (NULL);
		if (stt_buffer[0] == '\0')
			return (ft_read_err(&buffer, &stt_buffer));
	}
	free(buffer);
	return (stt_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stt_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stt_buffer = ft_read(fd, stt_buffer);
	if (!stt_buffer)
		return (NULL);
	line = ft_get_pre_str(stt_buffer);
	if (!line)
		return (NULL);
	stt_buffer = ft_get_post_str(stt_buffer);
	return (line);
}
