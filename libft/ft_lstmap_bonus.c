/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:37:41 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/29 23:29:00 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*present_lst;
	void	*ptr;

	if (!lst || !f || !del)
		return ((t_list *) NULL);
	new_lst = NULL;
	while (lst)
	{
		ptr = f(lst -> content);
		present_lst = ft_lstnew(ptr);
		if (!present_lst)
		{
			del(ptr);
			ft_lstclear(&new_lst, del);
			return ((t_list *) NULL);
		}
		ft_lstadd_back(&new_lst, present_lst);
		lst = lst -> next;
	}
	return (new_lst);
}
