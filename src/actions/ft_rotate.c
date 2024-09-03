/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:42:27 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/03 23:22:54 by xenia            ###   ########.fr       */
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
void ft_rotate(t_list **lst)
{
	t_list *first;
	t_list *tmp;

	if (!*lst)
		return ;
	if (!(*lst)->content || !(*lst)->next)
		return ;
	first = ft_lstnew((*lst)->content->value);
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	ft_lstdelone(tmp, &ft_del_cont);
	ft_lstadd_back(lst, first);
	return ;
}

void ft_rb(t_map **map)
{
	t_dlist *new;
	t_dlist *first;

	if (!(*map)->stack_b->lst)
		return ;
	if (!(*map)->stack_b->lst->value
		|| !(*map)->stack_b->lst->next)
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
}

void ft_ra(t_map **map)
{
	t_dlist *new;
	t_dlist *first;

	if (!(*map)->stack_a->lst)
		return ;
	if (!(*map)->stack_a->lst->value
		|| !(*map)->stack_a->lst->next)
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
}
