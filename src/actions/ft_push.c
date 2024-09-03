/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/03 23:20:30 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_decr_idx(t_dlist *lst)
{
	lst->index--;
}

static void ft_check_limits(t_stack **stack, int val)
{
	// if ((*stack)->max)
	// 	(*stack)->max = val;
	// if ((*stack)->min)
	// 	(*stack)->min = val;
}

/**
 * @brief
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * Decrease size of a, increase size of b.
 * Take care of indeces.
 *
 * @param map
 */
void ft_pb(t_map **map)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist	**lst_a;
	t_dlist **lst_b;

	lst_a = &(*map)->stack_a->lst;
	lst_b = &(*map)->stack_b->lst;
	if (!*lst_a || !(*lst_a)->value)
		return ;
	ft_check_limits(&(*map)->stack_b, (*lst_a)->value);
	new = ft_dlstnew((*lst_a)->value);
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	if (*lst_a)
		(*lst_a)->prev = NULL;
	ft_dlstdelone(temp);
	ft_dlstadd_front(lst_b, new);
	(*map)->stack_a->size--;
	(*map)->stack_b->size++;
	ft_dlstiter((*lst_a), &ft_decr_idx);

}

void ft_pa(t_map **map)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist	**lst_a;
	t_dlist **lst_b;

	lst_a = &(*map)->stack_a->lst;
	lst_b = &(*map)->stack_b->lst;
	if (!*lst_b || !(*lst_b)->value)
		return ;
	ft_check_limits(&(*map)->stack_a, (*lst_b)->value);
	new = ft_dlstnew((*lst_b)->value);
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	if (*lst_b)
		(*lst_b)->prev = NULL;
	ft_dlstdelone(temp);
	ft_dlstadd_front(lst_a, new);
	(*map)->stack_a->size++;
	(*map)->stack_b->size--;
	ft_dlstiter((*lst_b), &ft_decr_idx);
}
