/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:15:36 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/09 17:56:34 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_clean_exit(t_map **map)
{
	ft_free_map(map);
	exit (0);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_map	*map;

	ft_init_stack_a(&stack_a);
	ft_parse_args(&stack_a, argc, argv);
	if (stack_a->size > 1 && !ft_is_unique(&stack_a))
	{
		write(2, "Error\n", 6);
		ft_free_stack(&stack_a);
		exit(1);
	}
	ft_init_map(&map, stack_a);
	ft_is_sorted(map);
	printf("Map state: %d\n", map->state);
	if (!map->state)
		ft_sort(&map);
	if (map->state == 2)
		ft_sort_reverse(&map);
	if (map->state == 1)
		ft_clean_exit(&map);
	ft_free_map(&map);
	return (0);
}

