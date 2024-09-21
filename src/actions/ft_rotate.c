/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:42:27 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 12:59:53 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_map **map, int p);
void	ft_rb(t_map **map, int p);
void	ft_ra_x(t_map **map, int i, int p);
void	ft_rb_x(t_map **map, int i, int p);

/**
 * @brief	Rotates the a so that the first element becomes the last one.
 * 			Do nothing if size of a is 1 or less.
 *
 * 	Save pointer to the first node in a to the variable "first".
 * 	Shift a list pointer to the next node and unlink a from the first node.
 * 	Create a new node with value the same as the a first value.
 * 	Delete the first node.
 * 	Add "new" to the back of a.
 * 	Take care of indeces.
 * 	If p, writes action.
 *
 * @param map
 * @param p	Integer indicating if action should be written, 0 or any value.
 */
void	ft_ra(t_map **map, int p)
{
	t_dlist	*new;
	t_dlist	*first;

	if (!(*map)->stack_a->lst)
		return ;
	if (!(*map)->stack_a->lst->next)
		return ;
	if ((*map)->stack_a->size == 1)
		return ;
	first = (*map)->stack_a->lst;
	(*map)->stack_a->lst = first->next;
	new = ft_dlstnew((first)->value);
	(first)->next->prev = NULL;
	ft_dlstdelone(first);
	ft_dlstiter((*map)->stack_a->lst, &ft_decr_idx);
	ft_dlstadd_back(&(*map)->stack_a->lst, new);
	if (p)
		write(1, "ra\n", 3);
}

/**
 * @brief	Rotates the b so that the first element becomes the last one.
 * 			Do nothing if size of b is 1 or less.
 *
 * 	Save pointer to the first node in b to the variable "first".
 * 	Shift b list pointer to the next node and unlink b from the first node.
 * 	Create a new node with value the same as the b first value.
 * 	Delete the first node.
 * 	Add "new" to the back of b.
 * 	Take care of indeces.
 * 	If p, writes action.
 *
 * @param map
 * @param p	Integer indicating if action should be written, 0 or any value.
 */
void	ft_rb(t_map **map, int p)
{
	t_dlist	*new;
	t_dlist	*first;

	if (!(*map)->stack_b->lst)
		return ;
	if (!(*map)->stack_b->lst->next)
		return ;
	if ((*map)->stack_b->size == 1)
		return ;
	first = (*map)->stack_b->lst;
	(*map)->stack_b->lst = first->next;
	new = ft_dlstnew((first)->value);
	(first)->next->prev = NULL;
	ft_dlstdelone(first);
	ft_dlstiter((*map)->stack_b->lst, &ft_decr_idx);
	ft_dlstadd_back(&(*map)->stack_b->lst, new);
	if (p)
		write(1, "rb\n", 3);
}

/**
 * @brief Rotate a x times. If p, write actions.
 *
 * @param map
 * @param i Number of times a should be rotated
 * @param p Integer indicating if action should be written, 0 or any value.
 */
void	ft_ra_x(t_map **map, int i, int p)
{
	while (i > 0)
	{
		ft_ra(map, p);
		i--;
	}
}

/**
 * @brief Rotate b x times. If p, write actions.
 *
 * @param map
 * @param i Number of times b should be rotated
 * @param p Integer indicating if action should be written, 0 or any value.
 */
void	ft_rb_x(t_map **map, int i, int p)
{
	while (i > 0)
	{
		ft_rb(map, p);
		i--;
	}
}
