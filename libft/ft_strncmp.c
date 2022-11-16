#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *str1 = "hello";
// 	char *str2 = "heltr";
// 	printf("%d", strncmp(str1, str2, 4));
// }