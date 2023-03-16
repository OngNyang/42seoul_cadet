#include "push_swap.h"

int	main(int argc, char **argv)
{
	/*
	1. argc >=2 인지 확인
	2. argv가 적절한지 확인
	3. stack_a에 정수 채우기
	4. stack_b는 빈 스택
	5. stack_a 사이즈 측정
	6. 인덱스 할당(?)
	7. push_swap(?)
	8. stack_a free
	9. stack_b free
	*/
	t_deque	*stack_a;
	t_deque	*stack_b;
	
	int		i;

	if (argc <= 1)
		exit(1);
	check_argv(argv);	// argv가 적절한지 확인
	stack_b = new_deque();
	stack_a = new_deque();
	i = 0;
	while (i < argc - 1)
		push_r(stack_a, new_node(ft_atoi(argv[i++ + 1])));
	//--------------------------------
	//test code
	printf("\n------test code = stack_a------\n");
	t_node	*node = stack_a->front;
	while(node != NULL)
	{
		printf("%d-", node->data);
		node = node->next;
	}
	printf("\n");
	printf("-------------------------------\n\n");
	//-------------------------------
	// 스택 사이즈 측정(?)
	// 인덱스 할당(?)
	push_swap_quick_sort(stack_a, stack_b);		// push_swap(?)
	//--------------------------------
	//test code
	printf("\n\n------test code = stack_a------\n");
	node = stack_a->front;
	while(node != NULL)
	{
		printf("%d-", node->data);
		node = node->next;
	}
	printf("\n");
	printf("-------------------------------\n");
	//-------------------------------
	//--------------------------------
	//test code
	printf("\n------test code = stack_b------\n");
	node = stack_b->front;
	while(node != NULL)
	{
		printf("%d-", node->data);
		node = node->next;
	}
	printf("\n");
	printf("-------------------------------\n");
	//-------------------------------
	free(stack_a);
	free(stack_b);
	exit(0);
}