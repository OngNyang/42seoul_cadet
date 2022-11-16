#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char)s1;
	temp2 = (unsigned char)s2;
	i = 0;
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return (temp1[i] - temp2[i]);
		if (temp1[i] == '\0')
			return (0);
		i++;
	}
	return (0);

}
//두개의 메모리 단위를 비교