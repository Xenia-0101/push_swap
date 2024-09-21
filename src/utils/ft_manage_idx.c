/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:11:28 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 22:13:33 by xenia            ###   ########.fr       */
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
 *
 * 	Check limits in th list we are pushing into.
 * 	Check limits in the list we are pushing from.
 * 		If we are removing current max and
 * 		the list is not of size 1:
 * 			Init max to next value (constant)
 * 			Init temp to list minimum (variable)
 * 			Set new max
 * 		If we are removing current min and
 * 		the list is not of size 1:
 * 			Set min as the next value (constant)
 * 			Store the min in temp for comparision (variable)
 * 			Set new min
 *
 * @param s1 The stack we are pushing from.
 * @param s2 The stack we are pushing into.
 */
void	ft_check_limits(t_stack **s1, t_stack **s2)
{
	int	temp;

	if ((*s2)->max < (*s1)->lst->value)
		(*s2)->max = (*s1)->lst->value;
	if ((*s2)->min > (*s1)->lst->value)
		(*s2)->min = (*s1)->lst->value;
	if (((*s1)->max == (*s1)->lst->value)
		&& (*s1)->lst->next)
	{
		(*s1)->max = (*s1)->lst->next->value;
		temp = (*s1)->min;
		ft_dlstiter_max((*s1)->lst->next, temp, &(*s1)->max);
	}
	if (((*s1)->min == (*s1)->lst->value)
		&& (*s1)->lst->next)
	{
		(*s1)->min = (*s1)->lst->next->value;
		temp = (*s1)->min;
		ft_dlstiter_min((*s1)->lst->next, temp, &(*s1)->min);
	}
}
