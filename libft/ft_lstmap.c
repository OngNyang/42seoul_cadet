/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:37:41 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/27 15:55:20 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*present_lst;

	new_lst = NULL;
	if (!lst || !f || !del)
		return ((t_list *) NULL);
	while (lst)
	{
		present_lst = ft_lstnew(f(lst -> content));
		if (!present_lst)
		{
			ft_lstclear(&new_lst, del);
			return ((t_list *) NULL);
		}
		ft_lstadd_back(&new_lst, present_lst);
		lst = lst -> next;
	}
	return (new_lst);
}
