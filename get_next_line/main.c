#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// int main(void)
// {
// 	int fd;

// 	fd = 0;
// 	fd = open("./test.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%p\n", line);
// 	printf("%s", line);

// 	return (0);
// }

int	main(void)
{
	int		temp;
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((temp = (get_next_line(fd, &line)) > 0))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}