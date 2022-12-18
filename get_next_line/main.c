#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main(void)
{
	int		fpointer;
	char	*singleLine = malloc(1 * sizeof(char));

	fpointer = open("./test.txt", 256);
	while (singleLine != NULL)
	{
		free(singleLine);
		singleLine = get_next_line(fpointer);
		printf("%s", singleLine);
	}
	return (0);
}

// #define BUFFER_SIZE 1024

// static char	*ft_read_line(int fd, char *buf, char *backup)
// {
// 	int		count;

// 	count = read(fd, buf, BUFFER_SIZE); //버퍼사이즈 만큼 읽어 들이는데, 읽어 들인 사이즈를 저장해줌.
// 	printf("%d", count);
// 	return (backup);
// }

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		*buf;
// 	static char	*backup;

// 	if (fd < 0 || BUFFER_SIZE <= 0) //fd와 버퍼사이즈 유효성 검사.
// 		return (NULL);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //버퍼 메모리 동적할당
// 	if (!buf)
// 		return (NULL);
// 	line = ft_read_line(fd, buf, backup);
// 	return (line);
// }


// int main(void)
// {
// 	int		fpointer;
// 	char	*singleLine = malloc(1 * sizeof(char));

// 	fpointer = open("./test.txt", 256);
// 	get_next_line(fpointer);
// 	// while (singleLine != NULL)
// 	// {
// 	// 	free(singleLine);
// 	// 	singleLine = get_next_line(fpointer);
// 	// 	printf("%s", singleLine);
// 	// }
// 	return (0);
// }