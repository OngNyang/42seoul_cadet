void *ft_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return(s);
}
//for문 보다 빠를수 있기에 사용됨.