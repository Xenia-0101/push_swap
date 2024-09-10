/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/10 20:29:00 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_decr_idx(t_dlist *lst)
{
	lst->index--;
}

// from s1 to s2
static void	ft_check_limits(t_stack **s1, t_stack **s2)
{
	int	temp;
	// check limits in the list we are pushing into
	if ((*s2)->max < (*s1)->lst->value)
		(*s2)->max = (*s1)->lst->value;
	if ((*s2)->min > (*s1)->lst->value)
		(*s2)->min = (*s1)->lst->value;
	//check limits in the list we are pushing from
	if (((*s1)->max == (*s1)->lst->value)
		&& (*s1)->lst->next)
	{
		(*s1)->max = (*s1)->lst->next->value;
		temp = (*s1)->min;
		ft_dlstiter_2_max((*s1)->lst->next, temp, &(*s1)->max);
	}
	// if we are removing current minimum
	// if it's not a list of size 1
	if (((*s1)->min == (*s1)->lst->value)
		&& (*s1)->lst->next)
	{
		// set minimum as the next value - constant
		(*s1)->min = (*s1)->lst->next->value;
		// store this value for comparition - variable
		temp = (*s1)->min;
		ft_dlstiter_3_min((*s1)->lst->next, temp, &(*s1)->min);
	}
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
void	ft_pb(t_map **map)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist	**lst_a;
	t_dlist **lst_b;

	lst_a = &(*map)->stack_a->lst;
	lst_b = &(*map)->stack_b->lst;
	if (!*lst_a)
		return ;
	ft_check_limits(&(*map)->stack_a, &(*map)->stack_b);
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
	write(1, "pb\n", 3);
}

void	ft_pa(t_map **map)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist	**lst_a;
	t_dlist **lst_b;

	lst_a = &(*map)->stack_a->lst;
	lst_b = &(*map)->stack_b->lst;
	if (!*lst_b)
		return ;
	ft_check_limits(&(*map)->stack_b, &(*map)->stack_a);
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
	write(1, "pa\n", 3);
}
