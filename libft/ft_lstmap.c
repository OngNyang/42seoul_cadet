/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:37:41 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/25 17:22:41 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init_lst;
	t_list	*new_lst;
	t_list	*next_lst;

	ft_lstiter(lst, f);
	new_lst = ft_lstnew(lst -> content);
	init_lst = new_lst;
	while (lst != NULL)
	{
		next_lst = ft_lstnew(lst -> next -> content);
		new_lst -> next = next_lst;
		new_lst = new_lst -> next;
		lst = lst -> next;
	}
	new_lst = NULL;
	return (init_lst);
}
