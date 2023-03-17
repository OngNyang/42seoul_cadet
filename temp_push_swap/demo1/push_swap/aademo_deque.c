#include "push_swap.h"
#include <stdlib.h>



t_node	*new_node(int data)
{
	t_node	*node = (t_node*)malloc(sizeof(t_node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
/*
create new node
*/

t_deque	*new_deque(void)
{
	t_deque	*deque = (t_deque*)malloc(sizeof(t_deque));
	deque->front = NULL;
	deque->rear = NULL;
	return (deque);
}

void	push_front(t_deque *deque, int data)
{
	t_node	*node;

	node = new_node(data);
	if (deque->front == NULL)	//비어있으면 1개만 등록
	{
		deque->front = node;
		deque->rear = node;
	}
	else		//
	{
		node->next = deque->front;
		deque->front->prev = node;
		deque->front = node;
	}
}

void	push_rear(t_deque *deque, int data)
{
	t_node	*node;

	node = new_node(data);
	if (deque->rear == NULL)
	{
		deque->rear = node;
		deque->front = node;
	}
	else
	{
		node->prev = deque->rear;
		deque->rear->next = node;
		deque->rear = node;
	}
}

void	pop_front(t_deque *deque)
{
	t_node	*node;

	if (deque->front == NULL)
		return ;
	node = deque->front;
	deque->front = deque->front->next;
	if (deque->front == NULL)		//마지막 한개였으면
		deque->rear = NULL;
	else
		deque->front->prev = NULL;
	free(node);
}

void	pop_rear(t_deque *deque)
{
	t_node	*node;

	if (deque->rear == NULL)
		return ;
	node = deque->rear;
	deque->rear = deque->rear->prev;
	if (deque->rear == NULL)		//마지막 한개였으면
		deque->front = NULL;
	else
		deque->rear->next = NULL;
	free(node);
}

int	front(t_deque *deque)
{
	if (deque->front == NULL)
		return (-1);
	return (deque->front->data);
}

int	rear(t_deque *deque)
{
	if (deque->rear == NULL)
		return (-1);
	return (deque->rear->data);
}

//-------------------------


t_node	*pop_f(t_deque *deque)
{
	t_node	*node;

	if (deque->front == NULL)
		return (NULL);
	node = deque->front;
	deque->front = deque->front->next;
	if (deque->front == NULL)		//마지막 한개였으면
		deque->rear = NULL;
	else
		deque->front->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*pop_r(t_deque *deque)
{
	t_node	*node;

	if (deque->rear == NULL)
		return (NULL);
	node = deque->rear;
	deque->rear = deque->rear->prev;
	if (deque->rear == NULL)		//마지막 한개였으면
		deque->front = NULL;
	else
		deque->rear->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_f(t_deque *deque, t_node *node)
{
	if (deque->front == NULL)	//비어있으면 1개만 등록
	{
		deque->front = node;
		deque->rear = node;
	}
	else		//
	{
		node->next = deque->front;
		deque->front->prev = node;
		deque->front = node;
	}
}

void	push_r(t_deque *deque, t_node *node)
{
	if (deque->rear == NULL)	//비어있으면 1개만 등록
	{
		deque->front = node;
		deque->rear = node;
	}
	else		//
	{
		node->prev = deque->rear;
		deque->rear->next = node;
		deque->rear = node;
	}
}

t_bool	push(t_deque *deque_from, t_deque *deque_to)
{
	/*
	주소 바꾸고, prev, next 바꾸기
	*/
	if (deque_from->front == NULL)
		return (FALSE);
	push_f(deque_to, pop_f(deque_from));
	return (TRUE);
}
//--------------------------------------------

int	deque_size(t_deque *deque)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = deque->front;
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}


t_bool	swap(t_deque	*deque)
{
	/*
	최상단 2대 바꾸기.
	data값만 바꾸면 되는거 아님?
	*/
	int	temp;

	if (deque->front == deque->rear)	//원소의 갯수가 0,1개일때만 가능한 상황
		return (FALSE);
	temp = deque->front->data;
	deque->front->data = deque->front->next->data;
	deque->front->next->data = temp;
	return (TRUE);
}

//---------------------

t_bool	rotate(t_deque *deque)
{
	/*
	최상단을 최하단으로 내리면 되는거 아닌가.
	*/
	if (deque->front == NULL)	//원소의 갯수가 0개일때
		return (FALSE);
	push_r(deque, pop_f(deque));
	return (TRUE);
}

t_bool	rev_rotate(t_deque *deque)
{
	if (deque->rear == NULL)
		return (FALSE);
	push_f(deque, pop_r(deque));
	return (TRUE);
}

//-------------------------------------

int	main(int argc, char **argv)
{
	/*
	argc-1 만큼 반복 돌면서, new_node 해서 push_rear,
	근데 atoi 해야할듯
	*/
	t_deque	*deque_a;
	t_deque	*deque_b;
	t_node	*node;
	int		i;

	deque_a = malloc(sizeof(t_deque) * 1);
	i = 0;
	while (i < argc - 1)	//스택 a에 저장
	{
		push_rear(deque_a, ft_atoi(argv[i + 1]));
		i++;
	}


	node = deque_a->front;
	while(1)	//스택 a 출력
	{
		ft_putnbr_fd(node->data, 1);
		if (node == deque_a->rear)
			break ;
		node = node->next;
	}
	ft_putchar_fd('\n', 1);

	deque_b = malloc(sizeof(t_deque) * 1);
	push(deque_a, deque_b);
	rotate(deque_a);
	rev_rotate(deque_a);
	// push(deque_a, deque_b);
	// swap(deque_a);

	node = deque_b->front;
	while (node != NULL)	//deque b 출력
	{
		ft_putnbr_fd(node->data, 1);
		node = node->next;
	}
	ft_putchar_fd('\n', 1);

	node = deque_a->front;
	while(1)	//스택 a 출력
	{
		ft_putnbr_fd(node->data, 1);
		if (node == deque_a->rear)
			break ;
		node = node->next;
	}
	ft_putchar_fd('\n', 1);


	return (0);
}