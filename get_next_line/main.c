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