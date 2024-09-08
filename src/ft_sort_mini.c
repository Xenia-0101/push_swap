/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:56:46 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 16:57:15 by xenia            ###   ########.fr       */
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
	}
	if (max_i == 0)
	{
		ft_ra(map);
	}
	if (stack->min != stack->lst->value)
	{
		ft_sa(map);
	}
}

void ft_sort_4(t_map **map)
{
	ft_pb(map);
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
	}
	else if (val_b > (*map)->stack_a->max)
	{
		ft_pa(map);
		ft_ra(map);
	}
	else
	{
		size_t temp_i;
		// itterate sorted list and find first value that is larger
		temp_i = ft_dlstiter_v_4((*map)->stack_a->lst, val_b);
		if (temp_i == 0)
		{
			ft_pa(map);
		}
		else if (temp_i == 1)
		{
			ft_ra(map);
			ft_pa(map);
			ft_rra(map);
		}
		else
		{
			ft_rra(map);
			ft_pa(map);
			ft_rra(map);
			ft_rra(map);
		}
	}
}

// void ft_sort_5(t_map **map)
// {
// 	size_t temp_i;
// 	// t_pun pun;
// 	int res;
// 	int val_b;

// 	ft_pb(map);
// 	write(1, "pb\n", 3);
// 	ft_sort_4(map);
// 	// find position for el in b
// 	// itterate sorted list and find first value that is larger
// 	val_b = (*map)->stack_b->lst->value;
// 	temp_i = ft_dlstiter_v_4((*map)->stack_a->lst, val_b);
// 	// calculate the cost of pushing val b to correct position
// 	if (val_b > (*map)->stack_a->max)
// 	{
// 		ft_pa(map);
// 		ft_ra(map);
// 		write(1, "pa\nra\n", 6);
// 	}
// 	else if (val_b < (*map)->stack_a->min)
// 	{
// 		ft_pa(map);
// 		write(1, "pa\n", 3);
// 	}
// 	else
// 	{
// 		res = ft_calc_act_big(map, (int)temp_i, 0);
// 		printf("Configuration no %d\n", res);
// 		ft_calc_pun_big(map, (*map)->stack_a->lst, (int)temp_i, 0);
// 		ft_do_act_big(map, (*map)->stack_a->lst->pun, res);
// 		ft_pa(map);
// 		// ft_redo_act(map, &pun, res);
// 	}
// }

