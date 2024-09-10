/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:42:27 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/10 20:32:24 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_decr_idx(t_dlist *lst)
{
	lst->index--;
}
/**
 * @brief	Rotates the list variable lst is pointing to,
 * 			so that the fires element becomes the last one.
 *
 * 	Create a new node ("first") with cont.value the same as the lst first node cont.value.
 * 	Shift lst pointer to the next node and delete the first node.
 * 	Add "first" to the back of the lst.
 *
 * @param lst A pointer to the pointer of the list to be rotated.
 */
void	ft_rb(t_map **map, int p)
{
	t_dlist *new;
	t_dlist *first;

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

void	ft_ra(t_map **map, int p)
{
	t_dlist *new;
	t_dlist *first;

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

void	ft_ra_x(t_map **map, int i, int p)
{
	while (i > 0)
	{
		ft_ra(map, p);
		i--;
	}
}

void	ft_rb_x(t_map **map, int i, int p)
{
	while (i > 0)
	{
		ft_rb(map, p);
		i--;
	}
}
