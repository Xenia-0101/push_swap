/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:11:28 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 21:04:30 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_decr_idx(t_dlist *lst)
{
	lst->index--;
}

void	ft_incr_index(t_dlist *lst)
{
	if (!lst)
		return ;
	lst->index++;
}


/**
 * @brief Check limits in stacks when pushing values.
 * Compare and adjust min and max in the s2.
 * Compare limits in the stack we are pushing from:
 *  If the number pushed is min or max, find new limit
 *
 * @param s1 The stack we are pushing from.
 * @param s2 The stack we are pushing into.
 */
void	ft_check_limits(t_stack **s1, t_stack **s2)
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
		ft_dlstiter_max((*s1)->lst->next, temp, &(*s1)->max);
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
		ft_dlstiter_min((*s1)->lst->next, temp, &(*s1)->min);
	}
}
