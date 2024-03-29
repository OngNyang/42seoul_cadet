#include "pipex.h"


t_deque	*new_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	deque->front = NULL;
	deque->rear = NULL;
	return (deque);
}

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

void	push_r(t_deque *deque, t_node *node)
{
	if (deque->rear == NULL)
	{
		deque->front = node;
		deque->rear = node;
	}
	else
	{
		node->prev = deque->rear;
		deque->rear->next = node;
		deque->rear = node;
	}
	node->idx = deque_size(deque) - 1;
}