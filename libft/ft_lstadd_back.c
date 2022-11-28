/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:36:09 by hyejeong          #+#    #+#             */
/*   Updated: 2022/11/28 15:33:53 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ((void) NULL);
	else
	{
		if (*lst)
		{
			temp = ft_lstlast(*lst);
			temp -> next = new;
		}
		else
			*lst = new;
	}
}
