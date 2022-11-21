#include "libft.h"

int	atoi(const char *nptr)
{
	long long	sign;
	int			i;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	if (*nptr = '\0')
		return (0);
	if (*nptr = '-')
		sign = -1;
	while (*(nptr + i) != '\0')
	{
		if (*(nptr + i) >= '0' && *(nptr + i) <= '9')
		{
			res = res * 10 + *(nptr + i) - '0';
		}
		else
		{
			break;
		}
		i++;
	}
	return (int)(res * sign);
}