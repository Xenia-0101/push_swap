/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:42:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/03 23:45:53 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_reverse_algo(t_map **map)
{
	ft_init_stack_b(map);
	ft_pb(map);
	ft_pb(map);
	ft_rb(map);
	write(1, "pb\npb\nrb\n", 9);
	while ((*map)->stack_a->size > 3)
	{
		ft_pb(map);
		write(1, "pb\n", 3);
	}
	ft_ra(map);
	ft_sa(map);
	write(1, "ra\nsa\n", 6);
	while ((*map)->stack_b->size)
	{
		ft_pa(map);
		ft_ra(map);
		write(1, "pa\nra\n", 6);
	}
	ft_free_map(map);
	exit (0);
}
void ft_sort_reverse(t_map **map)
{
	if ((*map)->size == 3)
		ft_sort_3(map);
	else
		ft_reverse_algo(map);
}
