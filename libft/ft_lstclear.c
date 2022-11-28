/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:36:53 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/28 15:37:27 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt_lst;

	while (*lst != NULL)
	{
		nxt_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nxt_lst;
	}
	*lst = NULL;
}
