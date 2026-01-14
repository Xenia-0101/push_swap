#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	main(void)
{
	t_node	*stack = NULL;

	stack = stack_new(10);

	printf("stack\n");
	printf("%d", stack->value);

	stack_add_back(&stack, 5);
	printf("%d", stack->next->value);
	
	return (0);
}
