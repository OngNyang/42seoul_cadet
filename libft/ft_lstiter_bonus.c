/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:37:21 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/29 23:28:58 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*nxt_lst;

	nxt_lst = lst;
	while (nxt_lst != NULL)
	{
		f(nxt_lst -> content);
		nxt_lst = nxt_lst -> next;
	}
}
