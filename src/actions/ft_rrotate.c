/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:12:24 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 13:01:49 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_map **map, int p);
void	ft_rrb(t_map **map, int p);
void	ft_rra_x(t_map **map, int i, int p);
void	ft_rrb_x(t_map **map, int i, int p);

/**
 * @brief	Rotates the a so that the last element becomes the first one.
 * 			Do nothing if size of a is 1 or less.
 *
 * 	Save pointer to the last node in a to the variable "last".
 * 	Create a new node with value the same as the a last value.
 * 	Unlink the last node from a.
 * 	Delete the last node.
 * 	Add "new" to the front of a.
 * 	If p, writes action.
 *
 * @param map
 * @param p	Integer indicating if action should be written, 0 or any value.
 */
void	ft_rra(t_map **map, int p)
{
	t_dlist	*new;
	t_dlist	*last;

	if (!(*map)->stack_a->lst)
		return ;
	if (!(*map)->stack_a->lst->next)
		return ;
	if ((*map)->stack_a->size == 1)
		return ;
	last = ft_dlstlast((*map)->stack_a->lst);
	new = ft_dlstnew((last)->value);
	(last)->prev->next = NULL;
	ft_dlstdelone(last);
	ft_dlstadd_front(&(*map)->stack_a->lst, new);
	if (p)
		write(1, "rra\n", 4);
}

/**
 * @brief	Rotates the b so that the last element becomes the first one.
 * 			Do nothing if size of b is 1 or less.
 *
 * 	Save pointer to the last node in b to the variable "last".
 * 	Create a new node with value the same as the b last value.
 * 	Unlink the last node from b.
 * 	Delete the last node.
 * 	Add "new" to the front of b.
 * 	If p, writes action.
 *
 * @param map
 * @param p	Integer indicating if action should be written, 0 or any value.
 */
void	ft_rrb(t_map **map, int p)
{
	t_dlist	*new;
	t_dlist	*last;

	if (!(*map)->stack_b->lst)
		return ;
	if (!(*map)->stack_b->lst->next)
		return ;
	if ((*map)->stack_b->size == 1)
		return ;
	last = ft_dlstlast((*map)->stack_b->lst);
	new = ft_dlstnew((last)->value);
	(last)->prev->next = NULL;
	ft_dlstdelone(last);
	ft_dlstadd_front(&(*map)->stack_b->lst, new);
	if (p)
		write(1, "rrb\n", 4);
}

/**
 * @brief Reverse rotate a x times. If p, write actions.
 *
 * @param map
 * @param i Number of times a should be rotated
 * @param p Integer indicating if action should be written, 0 or any value.
 */
void	ft_rra_x(t_map **map, int i, int p)
{
	while (i > 0)
	{
		ft_rra(map, p);
		i--;
	}
}

/**
 * @brief Reverse rotate b x times. If p, write actions.
 *
 * @param map
 * @param i Number of times a should be rotated
 * @param p Integer indicating if action should be written, 0 or any value.
 */
void	ft_rrb_x(t_map **map, int i, int p)
{
	while (i > 0)
	{
		ft_rrb(map, p);
		i--;
	}
}
