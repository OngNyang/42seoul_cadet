unsigned char * ㅋㅐ스팅하는 이유
	: 가장 기본적인 형태의  타입이다. c 공식 문서를 보면 이렇게 캐스팅 하라고 나온다.

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

	- void	*ft_bzero(void *s, size_t n)

2. ft_calloc.char

	: allocate memory whose size is equal to 'size' * nmemb.

	- void	*ft_calloc(size_t nmemb, size_t size)

3. ft_itoa.c

	: transform integer to ascii character.

	- static int	get_size(long long num);

	- static char	*fill_mem(char *res, int n);
				
	- char			*ft_itoa(int n);
	- static char	*fill_zero(char *res);

4. ft_memmove.c
	
	: make memory block move to pointed area.

	void	*ft_memmove(void *dst, const void *src, size_t len);
		dst의 주소가 src보다 앞에 있는경우 덮어 씌어질 위험이 있는데 이부분으 조심하여
		케이스로 나누어 처리해주어야 한다.

5. ft_split.c

	: 문자열을 구분자 기준으로 나누고 2중 배열에 저장

	static size_t	cnt_word(const char *s, char charset);
		구분자 기준으로 나누어진 문자열의 갯수를 세어줌.
	static char	*get_word(const char *s, char charset);
		calloc으로 메모리를 할당받고 ft_strlcpy으로 문자 할당해줌
	static char	**freeing(char **s);
		만약 메모리 할당 실패하면, 메모리를 free해줘야 하는데, 주의할점은 그때 당시의 메모리 뿐만 아니라 2차원 배열의
		모든 메모리를 다 free해줘야 한다.
	char	**ft_split(char const *s, char c);

6. ft_strnstr.c

	: 문자열 내에 특정 문자열이 있는지 확인하고, 있다면 그 주소를 리턴한다.

	char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
		len 만큼 있는것이 중요해서, 기준 문자열에서 특정 문자열을 찾을때 기준 문자열에서 len 만큼 이상이
		남아 있는지 확인해야 한다.

7. ft.substr.c

	: 메모리를 할당해 주어진 문자열의 특정 위치부터 특정 크기만큼 복사한다. 

	char	*ft_substr(char const *s, unsigned int start, size_t len)
		복사할 사이즈를 결정하는데 조건을 나누어 주는것이 중요하다.

