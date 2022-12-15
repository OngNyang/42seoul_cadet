#include "get_next_line.h"
#define BUFFER_SIZE 1024

char	*ft_get_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = (char *)malloc(BUFFER_SIZE + 1);	//버퍼 생성
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes > 0) //line에 \n이 없고,
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE); //버퍼사이즈만큼 읽어내고, 그 길이를 read_bytes에 저장
		if (read_bytes == -1) //read() 실패시 -1 리턴한다.
		{
			free(buffer); //버퍼 프리 해줌
			return (NULL);
		}
		buffer[read_bytes] = '\0'; //버퍼의 최후미를 \0로 채워줌
		line = ft_strjoin(line, buffer); //파라미터로 받은 line과 현재 함수에서 생성한 buffer를 붙여준다.
	}
	free(buffer);	//버퍼 할당한 메모리 프리.
	return (line);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	
}

char	*ft_get_next_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	if (!line[i])	//비어있는 문자열이 들어오면, 종료
		return (NULL);
	while (line [i] != '\0' && line[i] != '\n') // \0이나 \n이 없으때까지 인덱스를 증가시킨다.
		i++;
	str = (char *)malloc(i + 2); //왜 +2이지?
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n') //\0 \n이 아닐때까지, 스트링에 라인을 복사해준다.
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n') // \n인경우 \n까지 복사하고, 널 터미네이팅.
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd와 버퍼 사이즈 유효성 검사.
		return (NULL);
	line = ft_get_line(fd, line); //정적 변수에 문자열 저장
	if (!line)
		return (NULL);
	next_line = ft_get_next_line(line); //그 다음줄 받아오기.
	line = new_line(line);


}