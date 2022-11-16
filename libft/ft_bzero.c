void	*ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	int 			*temp;

	i = 0;
	temp = (int *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
//fill 0 from pointed address