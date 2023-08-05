/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:53:29 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/20 13:37:29 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_deque	*stack_a;
	t_deque	*stack_b;
	int		i;

	if (argc <= 1)
		exit(1);
	check_argv(argv);
	stack_b = new_deque();
	stack_a = new_deque();
	i = 0;
	while (i < argc - 1)
		push_r(stack_a, new_node(ft_atoi(argv[i++ + 1])));
	push_swap(stack_a, stack_b, argc - 1);
	free_node(stack_a);
	free_node(stack_b);
	exit(0);
}
