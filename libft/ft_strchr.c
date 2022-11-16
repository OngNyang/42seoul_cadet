char *strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);

}
//문자열 내에 일치하는 문자가 있는지 검사하는 함수
// #include <stdio.h>

// int main(void)
// {
// 	const char *str = "hello";
// 	int n = 111;
// 	printf("%d", strchr(str, n));
// }