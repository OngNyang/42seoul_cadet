/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:58:43 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/18 19:16:58 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// int main(void)
// {
// 		printf("\n\t-------ex06-------\n");
// 	printf("nb = 0\t\t소수아님\t :\t%d\n", ft_is_prime(0));
// 	printf("nb = 2\t\t소수임\t\t :\t%d\n", ft_is_prime(2));
// 	printf("nb = 4\t\t소수아님\t :\t%d\n", ft_is_prime(4));
// 	printf("nb = 1229\t소수임\t\t :\t%d\n", ft_is_prime(1229));
// 	printf("nb = -174\t유효하지않음\t :\t%d\n", ft_is_prime(-174));
// 	printf("nb = 174\t소수아님\t :\t%d\n", ft_is_prime(174));
// }