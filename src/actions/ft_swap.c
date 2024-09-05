/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:02:30 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/05 07:58:09 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */

void ft_swap(t_list *lst)
{
	int temp;

	if (!lst->content || !lst->next->content)
		return ;
	temp = lst->content->value;
	lst->content->value = lst->next->content->value;
	lst->next->content->value = temp;
}

void ft_sa(t_map **map)
{
	int val;
	t_act **act;
	t_dlist *temp;

	if (!(*map)->stack_a->lst)
		return ;
	if (!(*map)->stack_a->lst->next)
		return ;
	temp = (*map)->stack_a->lst->next;
	val = (*map)->stack_a->lst->value;
	act = &(*map)->stack_a->lst->acts;
	(*map)->stack_a->lst->value = temp->value;
	(*map)->stack_a->lst->acts = temp->acts;
	temp->value = val;
	temp->acts = *act;
}

void ft_sb(t_map **map)
{
	int val;
	t_act **act;
	t_dlist *temp;

	if (!(*map)->stack_b->lst)
		return ;
	if (!(*map)->stack_b->lst->next)
		return ;
	temp = (*map)->stack_b->lst->next;
	val = (*map)->stack_b->lst->value;
	act = &(*map)->stack_b->lst->acts;
	(*map)->stack_b->lst->value = temp->value;
	(*map)->stack_b->lst->acts = temp->acts;
	temp->value = val;
	temp->acts = *act;
}

