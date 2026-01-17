#include <stdlib.h>
#include "push_swap.h"

t_map	*map_new(t_node *node_a)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->stack_a = node_a;
	map->stack_b = NULL;
	return (map);
}

