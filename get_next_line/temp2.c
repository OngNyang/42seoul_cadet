#include "get_next_line.h"
#define BUFFER_SIZE 1024

static char	*ft_read_line(int fd, char *buf, char *backup)
{
	int		count;
	char	*temp_pointer;

	count = 1;
	while (count)
	{
		count = read(fd, buf, BUFFER_SIZE); //버퍼사이즈 만큼 읽어 들이는데, 읽어 들인 사이즈를 저장해줌.
		if (count == -1) //read()는 읽기에 실패했을때 -1을 리턴함.
			return (0);
		else if(count ==0)
			break ;
		buf[count] == '\0'; //널 터미네이팅
		
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd와 버퍼사이즈 유효성 검사.
		return (NULL)
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //버퍼 메모리 동적할당
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, backup);
}