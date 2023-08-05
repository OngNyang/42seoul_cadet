/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:00:39 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 19:16:46 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	i;

	nb = (long long)nb;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 2;
	if (nb >= 2)
	{
		while (i <= nb / i)
		{
			if (i * i == nb)
				return (i);
				i++;
		}
	}
	return (0);
}
// #include <stdio.h>
// #include <math.h>

// int main(void)
// {
// 	printf("\n\t-------ex05-------\n");
// 	printf("소수가 나오면 ft_sqrt은 0으로 반환됩니다.\n");
// 	printf("  nb값\t\tsqrt\t :     ft_sqrt\n");
// 	printf("nb = 1\t\t%.2f\t :\t%d\n", sqrt(1), ft_sqrt(1));
// 	printf("nb = 64\t\t%.2f\t :\t%d\n", sqrt(64), ft_sqrt(64));
// 	printf("nb = 100\t%.2f\t :\t%d\n", sqrt(100), ft_sqrt(100));
// 	printf("nb = 256\t%.2f\t :\t%d\n", sqrt(256), ft_sqrt(256));
// 	printf("nb = 256\t%.2f\t :\t%d\n", sqrt(200), ft_sqrt(200));
// 	printf("nb = 2147483647\n\t\t%.2f :\t%d\n", sqrt(2147483647),
// ft_sqrt(2147483647));
// }