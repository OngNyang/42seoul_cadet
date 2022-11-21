#include "libft.h"

char	*strdup(const char *s)
{
	int	i;
	int	s_len;
	char	*str;

	i = 0;
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!str)
		return (0);
	while (*(s + i) != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}