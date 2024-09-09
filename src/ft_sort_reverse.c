/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:42:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/09 18:26:08 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_rb(map);
	while ((*map)->stack_a->size > 3)
	{
		ft_pb(map);
	}
	ft_ra(map);
	ft_sa(map);
	while ((*map)->stack_b->size)
	{
		ft_pa(map);
		ft_ra(map);
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
	else
		ft_reverse_algo(map);
	ft_free_map(map);
	exit (0);
}
