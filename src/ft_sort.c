/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/22 08:36:41 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_big(t_map **map)
{
	int		min_i;
	t_stack	*stack_a;

	stack_a = (*map)->stack_a;
	ft_pb(map);
	ft_pb(map);
	ft_sort_big_1(map, stack_a, (*map)->stack_b);
	ft_sort_3(map);
	ft_sort_big_2(map, stack_a, (*map)->stack_b);
	min_i = 0;
	ft_dlstiter_v_last(stack_a->lst, stack_a->min, (int *)&min_i);
	if (min_i < stack_a->size / 2)
		ft_ra_x(map, min_i, 1);
	else
		ft_rra_x(map, stack_a->size - min_i, 1);
}

void	ft_sort(t_map **map)
{
	ft_init_stack_b(map);
	if ((*map)->size == 3)
		ft_sort_3(map);
	else if ((*map)->size == 4)
		ft_sort_4(map);
	else if ((*map)->size == 5)
		ft_sort_big(map);
	else
		ft_sort_big(map);
	ft_free_map(map);
	exit(0);
}
