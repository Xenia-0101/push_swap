#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_map
{
	struct s_node	*stack_a;
	struct s_node	*stack_b;

} t_map;

t_map	*map_new(t_node *node_a);

int parse_input(t_map *map, int argc, char **argv);

t_node	*stack_new(int value);
void	stack_add_back(t_node **stack, t_node *new);
int		stack_size(t_node *stack);

void	sa(t_map *map);
void	sb(t_map *map);

#endif
