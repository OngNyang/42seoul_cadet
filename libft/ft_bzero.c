/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:36:08 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/21 11:36:18 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(void *s, unsigned int n)
{
	unsigned int	i;
	int				*temp;

	i = 0;
	temp = (int *)s;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
//fill 0 from pointed address