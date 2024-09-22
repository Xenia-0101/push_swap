/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:42:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/22 17:21:06 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_algo(t_map **map);
void		ft_sort_reverse(t_map **map);

/**
 * @brief Algorithm to reverse order in stack.lst
 *
 * @param map
 */
static void	ft_reverse_algo(t_map **map)
{
	ft_init_stack_b(map);
	ft_pb(map);
	ft_pb(map);
	ft_rb(map, 1);
	while ((*map)->stack_a->size > 3)
	{
		ft_pb(map);
	}
	ft_ra(map, 1);
	ft_sa(map);
	while ((*map)->stack_b->size)
	{
		ft_pa(map);
		ft_ra(map, 1);
	}
}

/**
 * @brief Reverse order of the stack.lst based on stack size
 * 			Free map
 * 			Exit program
 *
 * @param map
 */
void	ft_sort_reverse(t_map **map)
{
	if ((*map)->size == 2)
		ft_sort_2(map);
	else if ((*map)->size == 3)
		ft_sort_3(map);
	else if ((*map)->size == 4)
	{
		ft_init_stack_b(map);
		ft_sort_4(map);
	}
	else if ((*map)->size == 5)
	{
		ft_init_stack_b(map);
		ft_sort_5_rev(map);
	}
	else
		ft_reverse_algo(map);
	ft_free_map(map);
	exit (0);
}
