#include "libft.h"

char	**ft_split(char const *s, char c)
{
	//구분자를 기준으로 문자열을 자름
	//문자열을 배열에 저장
	//각각 문자열의 마지막은 널
	//배열의 마지막은 널포인터
	char	**arr;

	arr = (char **)malloc(sizeof(char *));
	if (!arr)
		return (0);
	
}