#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

t_node	*stack_new(int value);
void	stack_add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);

#endif
