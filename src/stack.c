#include <stdlib.h>
#include "push_swap.h"

t_node	*stack_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	stack_add_back(t_node **stack, t_node *new)
{
	t_node	*cur;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
