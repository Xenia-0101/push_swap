/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 16:59:06 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_big(t_map **map)
{
	int curr_v;
	int max_i;
	int temp_v;
	int cost;
	int push_v;
	int push_i;
	t_dlist *temp;
	t_stack *stack_a;
	t_stack *stack_b;

	ft_pb(map);
	ft_pb(map);
	// i = 0
	// where to push ?? (index)
	// 		- if v > max || v < min: push above max
	// 		- the highest number that is lower than the current
	stack_a = (*map)->stack_a;
	stack_b = (*map)->stack_b;
	temp = stack_a->lst;

	// iterate lst at stack a
	while (stack_a->size > 3)
	{
		curr_v = temp->value;
		// printf("* value: %d\n", curr_v);

		// calculate ideal position
		if (curr_v > stack_b->max || curr_v < stack_b->min)
		{
			push_v = stack_b->max;
			push_i = ft_dlstiter_v(stack_b->lst, push_v);
		}
		else
		{
			push_v = stack_b->min;
			push_i = 0;
			ft_dlstiter_high_low(stack_b->lst, curr_v, &push_v, &push_i);
		}
		temp->ipo = push_i;
		// printf("\tpush v: %d  push i: %d\n", push_v, temp->ipo);
		// calculate conf
		ft_calc_act_big(map, &temp, temp->index, push_i);
		// printf("\t\tconf: %d\tcost: %d\n", temp->conf, temp->cost);
		ft_calc_pun_big(map, &temp, temp->index, push_i);
		// ft_print_pun(temp->pun);

		// TODO: To be optimised
		ft_do_act_big(map, temp->pun);
		temp = temp->next;
		ft_pb(map);

	}
	ft_sort_3(map);

	temp = stack_b->lst;
	while (stack_b->size > 0)
	{
		curr_v = temp->value;
		// printf("* value: %d\n", curr_v);

		if (curr_v > stack_a->max || curr_v < stack_a->min)
		{
			push_v = stack_a->min;
			push_i = ft_dlstiter_v(stack_a->lst, push_v);
		}
		else
		{
			push_v = stack_a->max;
			push_i = 0;
			ft_dlstiter_low_high(stack_a->lst, curr_v, &push_v, &push_i);
		}
		temp->ipo = push_i;
		// printf("\tpush v: %d  push i: %d\n", push_v, temp->ipo);

		// calculate conf
		ft_calc_act_big(map, &temp, push_i, temp->index);
		// printf("\t\tconf: %d\tcost: %d\n", temp->conf, temp->cost);
		ft_calc_pun_big(map, &temp, push_i, temp->index);
		// ft_print_pun(temp->pun);

		// TODO: To be optimised
		ft_do_act_big(map, temp->pun);
		temp = temp->next;
		ft_pa(map);
	}
	push_i = ft_dlstiter_v(stack_a->lst, stack_a->min);
	if (push_i > stack_a->size / 2)
		ft_ra_x(map, push_i);
	else
		ft_rra_x(map, push_i);
}

void ft_sort(t_map **map)
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
}

