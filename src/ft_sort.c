/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/07 11:50:20 by xenia            ###   ########.fr       */
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
	t_pun pun;
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
		res = ft_calc_act((*map)->stack_a, (*map)->stack_b, (int)temp_i, 0);
		printf("Configuration no %d\n", res);
		ft_calc_pun(map, &pun, (int)temp_i, 0);
		ft_do_act(map, &pun, res);
		ft_pa(map);
		ft_redo_act(map, &pun, res);
	}
}

void ft_sort_big(t_map **map)
{

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
}

