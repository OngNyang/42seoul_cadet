#include "get_next_line.h"
#define BUFFER_SIZE 42


static char	*ft_read(int fd, char *buffer, char *temp_line)
{
	ssize_t	len;

	len = 1;
	while (len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		else if (len == 0)
			break ;
		buffer[len] = '\0';
		if (!temp_line)
			temp_line = ft_strdup("");
		temp_line = ft_strjoin(temp_line, buffer);
		if (ft_strchr(temp_line, '\n') != 0)
			break ;
	}
	return (temp_line);
}

static char	*ft_slice(char *str)
{
	int		i;
	char	*new_str;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	new_str = ft_substr(str, 0, i + 1);
	if (!new_str)
		return (NULL);
	
	


	// \n이나  \0을 만날때까지 인덱스 전진
	//해당 범위 만큼 동적할당 뒤 복사해준다. 
	//복사한 문자열 널가드
	//널 터미네이팅.
}
//추출된 문자열 중에서, \0 이나 \n을 만나기 전까지의 문자들만 추출하여 반환한다.

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*temp_line;


	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = ft_read(fd, buffer, temp_line);

	//fd와 버퍼사이즈 유효성 검사.
	//버퍼 메모리 동적할당
	//버퍼 사이즈만큼 읽어서 저장한다. 개행을 만날때까지 해야 한다.
	//버퍼 비워준다.
	//주어진 문자열 중에서 \0, \n을 만나기 전까지의 문자들만 추출하여 저장.//주어진 문자열 중에서 \0, \n을 만나기 전까지의 문자들만 추출하여 저장.
}
