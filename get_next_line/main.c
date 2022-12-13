#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;

	fd = 0;
	fd = open("./test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%p\n", line);
	printf("%s", line);

	return (0);
}