/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:36:53 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/25 16:53:26 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*present_lst;
	t_list	*temp_lst;

	if (!lst || !del)
		return ;
	present_lst = *lst;
	while (present_lst != NULL)
	{
		temp_lst = present_lst;
		present_lst = present_lst -> next;
		ft_lstdelone(temp_lst, del);
	}
	*lst = (t_list *) NULL;
}
