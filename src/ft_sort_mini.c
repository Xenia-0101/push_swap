/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:56:46 by xenia             #+#    #+#             */
/*   Updated: 2024/09/09 18:20:49 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_4_algo(t_map **map, int val_b);
void		ft_sort_2(t_map **map);
void		ft_sort_3(t_map **map);
void		ft_sort_4(t_map **map);

/**
 * @brief Sort list of size 2
 *			Must be reverse sorted - rotate once
 * @param map
 */
void	ft_sort_2(t_map **map)
{
	ft_ra(map);
}

/**
 * @brief Sort list of size 3
 * 			Get index of the node with max value
 * 			Get the max node to the bottom of lst
 * 			If the value of first node is not min, swap nodes
 *
 * @param map
 */
void	ft_sort_3(t_map **map)
{
	t_stack	*stack;
	size_t	max_i;
	int		max;

	stack = (*map)->stack_a;
	max = (*map)->stack_a->max;
	max_i = ft_dlstiter_v((*map)->stack_a->lst, (*map)->stack_a->max);
	if (max_i == 0)
	{
		ft_ra(map);
	}
	if (max_i == 1)
	{
	}
		ft_rra(map);
	if (stack->min != stack->lst->value)
	{
		ft_sa(map);
	}
}

/**
 * @brief Find correct position for val_b and push it to stack a
 * 			Get the index of the node with the lowest value larger than val_b
 * 			-- stack a is sorted - find the first larger value
 * 			if index is 0 - pa
 * 			if index is 1 - ra, pa, rra
 * 			if index is 2 - rra, pa, rra, rra
 *
 * @param map
 * @param val_b
 */
static void	ft_sort_4_algo(t_map **map, int val_b)
{
	size_t	temp_i;

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

/**
 * @brief Sort list of size 4
 * 			Push one element to stack b
 * 			Sort stack a by calling ft_sort_3
 * 			Find correct position for the element in stack b:
 * 				If it is new min - pa
 * 				If it is new max - pa and ra
 * 				Else - call ft_sort_4_algo
 *
 * @param map
 */
void	ft_sort_4(t_map **map)
{
	int	val_b;

	ft_pb(map);
	ft_sort_3(map);
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
		ft_sort_4_algo(map, val_b);
	}
}

