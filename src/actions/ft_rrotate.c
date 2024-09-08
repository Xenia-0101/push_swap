/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:12:24 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/08 16:42:48 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/**
 * @brief 	Rotates the list variable lst is pointing to, s
 * 			o that the last node becomes the first node.
 * 	Get reach of the last node ("tmp") and set the second-to-last.next to null.
 * 	Create a new node "last" which will have the same value as the last node.
 * 	Add the "last" node to the front of the list.
 * 	** No need to reset indices - taken care for in the ft_lst_addfront **
 *
 * @param lst A pointer to the pointer of the list to be rotated.
 */

void	ft_rrb(t_map **map)
{
	t_dlist	*new;
	t_dlist	*last;

	last = ft_dlstlast((*map)->stack_b->lst);
	new = ft_dlstnew((last)->value);
	(last)->prev->next = NULL;
	ft_dlstdelone(last);
	ft_dlstadd_front(&(*map)->stack_b->lst, new);
	write(1, "rrb ", 4);
}

void	ft_rra(t_map **map)
{
	t_dlist *new;
	t_dlist *last;

	last = ft_dlstlast((*map)->stack_a->lst);
	new = ft_dlstnew((last)->value);
	(last)->prev->next = NULL;
	ft_dlstdelone(last);
	ft_dlstadd_front(&(*map)->stack_a->lst, new);
	write(1, "rra ", 4);
}

void	ft_rra_x(t_map **map, int i)
{
	while (i > 0)
	{
		ft_rra(map);
		i--;
	}
}

void	ft_rrb_x(t_map **map, int i)
{
	while (i > 0)
	{
		ft_rrb(map);
		i--;
	}
}
