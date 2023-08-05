/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:08:09 by hyeondle          #+#    #+#             */
/*   Updated: 2022/07/15 16:58:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int num)
{
	if (num > 64 && num < 91)
		return (num + 32);
	else
		return (num);
}