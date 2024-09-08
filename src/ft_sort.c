/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 11:24:17 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_sort_3(t_map **map)
{
	t_stack *stack;
	int	max;
	size_t max_i;

	stack = (*map)->stack_a;
	max = (*map)->stack_a->max;
	max_i = ft_dlstiter_v((*map)->stack_a->lst, (*map)->stack_a->max);
	if (max_i == 1)
	{
		ft_rra(map);
		write(1, "rra\n", 4);
	}
	if (max_i == 0)
	{
		ft_ra(map);
		write(1, "ra\n", 4);
	}
	if (stack->min != stack->lst->value)
	{
		ft_sa(map);
		write(1, "sa\n", 3);
	}
}

void ft_sort_4(t_map **map)
{
	ft_pb(map);
	write(1, "pb\n", 3);
	// sort a
	ft_sort_3(map);
	// pa --- find correct position (index above which to push -->next lowest)
		// if val is == to stack min -> pa
		// if val is == to stack max -> pa, ra
		// else iterate list by value
			// -- init temp var for the first element
			// -- if list val is < val to push && > temp var: reset temp var


	// problems with 0
	int val_b;
	val_b = (*map)->stack_b->lst->value;
	if (val_b < (*map)->stack_a->min)
	{
		ft_pa(map);
		write(1, "pa\n", 3);
	}
	else if (val_b > (*map)->stack_a->max)
	{
		ft_pa(map);
		write(1, "pa\n", 3);
		ft_ra(map);
		write(1, "ra\n", 3);
	}
	else
	{
		size_t temp_i;
		// itterate sorted list and find first value that is larger
		temp_i = ft_dlstiter_v_4((*map)->stack_a->lst, val_b);
		if (temp_i == 0)
		{
			ft_pa(map);
			write(1, "pa\n", 3);
		}
		else if (temp_i == 1)
		{
			ft_ra(map);
			write(1, "ra\n", 3);
			ft_pa(map);
			write(1, "pa\n", 3);
			ft_rra(map);
			write(1, "rra\n", 4);
		}
		else
		{
			ft_rra(map);
			write(1, "ra\n", 3);
			ft_pa(map);
			write(1, "pa\n", 3);
			ft_rra(map);
			write(1, "rra\n", 4);
			ft_rra(map);
			write(1, "rra\n", 4);
		}
	}
}

void ft_sort_5(t_map **map)
{
	size_t temp_i;
	// t_pun pun;
	int res;
	int val_b;

	ft_pb(map);
	write(1, "pb\n", 3);
	ft_sort_4(map);
	// find position for el in b
	// itterate sorted list and find first value that is larger
	val_b = (*map)->stack_b->lst->value;
	temp_i = ft_dlstiter_v_4((*map)->stack_a->lst, val_b);
	// calculate the cost of pushing val b to correct position
	if (val_b > (*map)->stack_a->max)
	{
		ft_pa(map);
		ft_ra(map);
		write(1, "pa\nra\n", 6);
	}
	else if (val_b < (*map)->stack_a->min)
	{
		ft_pa(map);
		write(1, "pa\n", 3);
	}
	else
	{
		// res = ft_calc_act((*map)->stack_a, (*map)->stack_b, (int)temp_i, 0);
		// printf("Configuration no %d\n", res);
		// ft_calc_pun(map, &pun, (int)temp_i, 0);
		// ft_do_act(map, &pun, res);
		// ft_pa(map);
		// ft_redo_act(map, &pun, res);
	}
}

void ft_sort_big(t_map **map)
{	printf("sort big\n");
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
	write(1, "pb\npb\n", 6);
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
		write(1, "pb\n", 3);

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
		write(1, "pa\n", 3);
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
		ft_sort_5(map);
	else
		ft_sort_big(map);
	printf("Sorting\n");
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
	printf("***\n");
	ft_dlstiter((*map)->stack_b->lst, &ft_print_lst);
}

