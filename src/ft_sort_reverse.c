/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:42:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/08 16:56:11 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_free_map(map);
	exit (0);
}
void	ft_sort_reverse(t_map **map)
{
	if ((*map)->size == 3)
		ft_sort_3(map);
	else
		ft_reverse_algo(map);
}
