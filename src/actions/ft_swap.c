/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:02:30 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/08 16:43:24 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */

void	ft_sa(t_map **map)
{
	int		val;
	t_act	**act;
	t_dlist	*temp;

	if (!(*map)->stack_a->lst)
		return ;
	if (!(*map)->stack_a->lst->next)
		return ;
	temp = (*map)->stack_a->lst->next;
	val = (*map)->stack_a->lst->value;
	(*map)->stack_a->lst->value = temp->value;
	temp->value = val;
	write(1, "sa ", 3);
}

void	ft_sb(t_map **map)
{
	int		val;
	t_act	**act;
	t_dlist	*temp;

	if (!(*map)->stack_b->lst)
		return ;
	if (!(*map)->stack_b->lst->next)
		return ;
	temp = (*map)->stack_b->lst->next;
	val = (*map)->stack_b->lst->value;
	(*map)->stack_b->lst->value = temp->value;
	temp->value = val;
	write(1, "sb ", 3);
}

