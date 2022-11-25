/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:37:21 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/25 17:00:44 by hyejeong         ###   ########.fr       */
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
