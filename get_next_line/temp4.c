#include "get_next_line.h"
#define BUFFER_SIZE 42

char	*ft_read(int fd, char *buffer, char *stt_buffer)
{
	ssize_t	len;

	len = 1;
	while (len)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0) // fail read()
			return (NULL);
		if (len == 0) // EOF
			break ;
		buffer[len] = '\0'; //null terminated
		if (!stt_buffer)
			stt_buffer = ft_strdup("");
		stt_buffer = ft_strjoin(stt_buffer, buffer);
		if (!stt_buffer)
			return (NULL);
		if (ft_strchr(stt_buffer, '\n') != 0)
			break ;
	}
	return (stt_buffer);
}

char	*ft_slice(char *line)
{
	ssize_t	i;
	char	*str;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0') // \n \0 을 만나기 전까지 전진 시켜줌.
		i++;
	str = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!str)
		return (NULL);
	line[i] = '\0';
	return (str);
}


char	*get_next_line(int fd)
{
	static char	*stt_buffer;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // \0을 넣어주기 위해 +1 해줌
	if(!buffer)
		return (NULL);
	line = ft_read(fd, buffer, stt_buffer);
	if (!line)
		return (NULL);
	stt_buffer = ft_slice(line);
	return (line);
}