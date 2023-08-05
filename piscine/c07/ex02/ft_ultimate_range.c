/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:07:15 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 16:05:23 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	arr_len;
	long long	i;
	int			*a;

	arr_len = (long long)max - (long)min;
	if (arr_len <= 0)
		return (0);
	a = (int *)malloc(sizeof(int) * arr_len);
	if (!a)
		return (-1);
	*range = a;
	i = 0;
	while (i < arr_len)
	{
		a[i] = min + i;
		i++;
	}
	return (arr_len);
}
// #include <stdio.h>
// #include <limits.h>

// int	main (void)
// {	
// 		printf("\n--ex02--\n\n");
// 	int i;

// 	int	*arr2;
// 	int	min2;
// 	int max2;

// 	// min2 = INT_MIN;
// 	// max2 = INT_MAX;
// 	min2 = 10;
// 	max2 = 20;
// 	i = 0;
// 	ft_ultimate_range(&arr2, min2, max2); // &
// 	while (min2 < max2)
// 	{
// 		printf("%d\n", arr2[i++]);
// 		min2++;
// 	}

// }