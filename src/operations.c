
#include "push_swap.h"


void sa(t_map *map){
    int c;

    if (!map || !map->stack_a)
        return;
    if (stack_size(map->stack_a) < 2)
        return;
    
    c = map->stack_a->value;
    map->stack_a->value = map->stack_a->next->value;
    map->stack_a->next->value = c;
}

void sb(t_map *map){
    int c;

    if (!map || !map->stack_b)
        return;
    if (stack_size(map->stack_b) < 2)
        return;
    
    c = map->stack_b->value;
    map->stack_b->value = map->stack_b->next->value;
    map->stack_b->next->value = c;
}