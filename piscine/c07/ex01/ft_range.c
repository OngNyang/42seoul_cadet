/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:03:27 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 16:00:19 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*arr;
	long long	arr_len;
	long long	i;

	arr_len = (long long)max - (long long)min;
	if (arr_len <= 0)
		return (0);
	arr = (int *)malloc(sizeof(int) * arr_len);
	i = 0;
	while (arr_len != 0)
	{
		*(arr + i) = min + i;
		arr_len--;
		i++;
	}
	return (arr);
}
//  #include <stdio.h>
// #include <limits.h>

// int	main (void)
// {	
// 	printf("\n--ex01--\n\n");

// 	int i;
// 	int	min;
// 	int	max;
// 	int *arr;

// 	i = 0;
// 	min = -10;
// 	max = 10;
// 	arr = ft_range(min, max);
// 	while (min < max)
// 	{
// 		printf("%d\n", arr[i++]);
// 		min++;
// 	}
// }