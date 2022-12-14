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
		buf[count] = '\0'; //널 터미네이팅
		if (!backup)
			backup = ft_strdup(""); //backup이 비어있다면, 아무것도 없는 문자열을 만들어준다.
		temp_pointer = backup;
		backup = ft_strjoin(temp_pointer, buf); //버퍼와 backup 문자열을 융합해준다.
		if (!backup)
			return (NULL);
		free(temp_pointer); //임시로 사용한 메모리 해제해줌.
		temp_pointer = NULL; //임시 포인터 변수 다시 초기화 해줌.
		if (ft_strchr(buf, '\n')) //개행을 만나면 멈춘다.
			break ;
	}
	return (backup);
}
//버퍼 사이즈가 개행을 만나기 전에 끝난다면 -> while 문 반복
//버퍼 사이즈가 개행을 1개만 담고 다음 개행 이저에 끝난다면 -> while문 break. 
//버퍼 사이즈가 전문을 다 담는다면 -> while문 break.
//버퍼 사이즈가 개행을 못만나면, 반복해서 읽기를 한다.

static char *ft_extract(char *line)
{
	int	i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0') // \n이나  \0을 만날때까지 인덱스 전진
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i); //해당 범위 만큼 동적할당 뒤 복사해준다. 
	if (!result)
		return (NULL);
	if (result[0] == '\0') //복사한 문자열 널가드
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0'; //널 터미네이팅.
	return (result);
}
//추출된 문자열 중에서, \0 이나 \n을 만나기 전까지의 문자들만 추출하여 반환한다.

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0) //fd와 버퍼사이즈 유효성 검사.
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //버퍼 메모리 동적할당
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, buf, backup); //버퍼 사이즈만큼 읽어서 저장한다. 개행을 만날때까지 해야 한다.
	free(buf); //버퍼 비워준다.
	buf = NULL;
	if (!line)
		return (NULL);
	backup = ft_extract(line); //주어진 문자열 중에서 \0, \n을 만나기 전까지의 문자들만 추출하여 저장.
	return (line);
}