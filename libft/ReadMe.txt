1. ft_atoi.c

	: transform 'ascii char' to 'integer'.

	- size_t	check_pre(const char *nptr);
			check whether the parameter is +, \t, \v, \f, \r, \n, space. and return an index where those ascii chars don't exist.
	- int		check_sign(const char *nptr);
			check whether the parameter is +, -.
	- int		ft_atoi(const char *nptr);
			check those ascii chars. and make char to integer

2. ft_bzero.c

	: fill 0 from pointed address.

	void	*ft_bzero(void *s, size_t n)

2. ft_calloc.char

	: