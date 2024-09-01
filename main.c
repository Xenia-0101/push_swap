/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:15:36 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/01 23:44:44 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_print_lst(t_dlist *lst)
{
	// printf("***%d***\n", cont->value);
	printf("%ld\t%d\n", lst->index, lst->value);
}

void ft_sort(t_map **map)
{
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
};
void ft_sort_reverse(t_map **map)
{
	printf("sort reverse\n");
}

void ft_return_sorted(t_map **map)
{
	printf("is sorted\n");
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

	ft_is_sorted(map);

	// check if list is sorted
	if (!map->state)			// TODO: treat sorted list
		ft_sort(&map);	// SORT;
	if (map->state == 2)
		ft_sort_reverse(&map);	// SORT REVERSE
	if (map->state == 1)
		ft_return_sorted(&map);	// RETURN SORTED

	// printf("%d %d\n",stack_a->min, stack_a->max);
	ft_free_map(&map);
	// free(tab);

	return (0);
}

