/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:56:37 by hyejeong          #+#    #+#             */
/*   Updated: 2022/10/04 20:56:44 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	a;
	int	idx;

	idx = 0;
	a = (size + 1) / 2;
	while (a != 0)
	{
		temp = *(tab + idx);
		*(tab + idx) = *(tab + size - idx - 1);
		*(tab + size - idx - 1) = temp;
		idx++;
		a--;
	}
}
