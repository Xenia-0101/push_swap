/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:15:36 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/01 23:21:35 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_print_lst(t_dlist *lst)
{
	// printf("***%d***\n", cont->value);
	printf("%ld\t%d\n", lst->index, lst->value);
}
int ft_is_sorted(t_map *map)
{
	int is_asc;
	int is_des;
	t_dlist *curr;
	t_dlist *next;

	is_asc = 1;
	is_des = 2;
	curr = map->stack_a->lst;
	while (curr->next && (is_asc || is_des))
	{
		if (curr->value < curr->next->value)
			is_des = 0;
		else if (curr->value > curr->next->value)
			is_asc = 0;
		curr = curr->next;
	}
	map->state = is_asc + is_des;
	return (map->state);
}
int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_map	*map;

	ft_init_stack_a(&stack_a);

	// parse args - check the argc and build stack A
	ft_parse_args(&stack_a, argc, argv);

	// check if nums are unique
	if (!ft_is_unique(&stack_a))
	{
		write(2, "\033[0;31mERROR: Numbers are not unique.\033[0m\n", 42);
		ft_free_stack(&stack_a);
		exit(1);
	}
	// initialize map
	ft_init_map(&map, stack_a);

	// check if list is sorted
	if (ft_is_sorted(map))			// TODO: treat sorted list
		printf("\033[0;32mlist is sorted\033[0m\n");

	ft_dlstiter(stack_a->lst, &ft_print_lst);
	// printf("%d %d\n",stack_a->min, stack_a->max);
	ft_free_map(&map);
	// free(tab);

	return (0);
}

