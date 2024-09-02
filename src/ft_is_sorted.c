/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:35:27 by xenia             #+#    #+#             */
/*   Updated: 2024/09/02 07:06:53 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_check_size(t_map *map)
{
	if (map->size == 1)
		map->state = 1;
	return (map->state);
}

int	ft_is_sorted(t_map *map)
{
	int		is_asc;
	int		is_des;
	t_dlist	*curr;
	t_dlist	*next;

	if (ft_check_size(map))
		return (map->state);
	is_asc = 1;
	is_des = 2;
	curr = map->stack_a->lst;
	while (curr->next && (is_asc || is_des))
	{
		if (curr->value < curr->next->value)
			is_des = 0;
		else if (curr->value > curr->next->value)
			is_asc = 0;
		curr = curr->next;
	}
	map->state = is_asc + is_des;


	return (map->state);
}
