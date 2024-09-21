/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:07:00 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 16:39:29 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstiter_high_low(t_dlist *lst, int v, int *tv, int *ti);
void	ft_dlstiter_low_high(t_dlist *lst, int v, int *tv, int *ti);
void	ft_dlstiter_cheap(t_dlist *lst, int *c, int pun[4]);

/**
 * @brief	Find the highest number in the list that is lower than v.
 *
 * @param lst	List to iterate
 * @param v		Value to compare against.
 * @param tv	Temporary value - highest number lower than v.
 * @param ti	Temporary index - index of the tv.
 */
void	ft_dlstiter_high_low(t_dlist *lst, int v, int *tv, int *ti)
{
	if (!lst)
		return ;
	if (lst->value < v && lst->value >= *tv)
	{
		*tv = lst->value;
		*ti = lst->index;
	}
	if (lst->next)
		ft_dlstiter_high_low(lst->next, v, tv, ti);
}

/**
 * @brief	Find the lowest number in the list that is larger than v.
 *
 * @param lst	List to iterate
 * @param v		Value to compare against.
 * @param tv	Temporary value - lowest number larger than v.
 * @param ti	Temporary index - index of the tv.
 */
void	ft_dlstiter_low_high(t_dlist *lst, int v, int *tv, int *ti)
{
	if (!lst)
		return ;
	if (lst->value > v && lst->value <= *tv)
	{
		*tv = lst->value;
		*ti = lst->index;
	}
	if (lst->next)
		ft_dlstiter_low_high(lst->next, v, tv, ti);
}

/**
 * @brief	Iterate the list and find the node with cost lower than c.
 *			Set the pun to the values of the cheap node.
 *
 * @param lst	List to iterate
 * @param c		Cost to compare against - init to the first node
 * @param pun	The action configuration
 */
void	ft_dlstiter_cheap(t_dlist *lst, int *c, int pun[4])
{
	if (!lst)
		return ;
	if (lst->cost < *c)
	{
		*c = lst->cost;
		pun[0] = lst->pun[0];
		pun[1] = lst->pun[1];
		pun[2] = lst->pun[2];
		pun[3] = lst->pun[3];
	}
	if (lst->next)
		ft_dlstiter_cheap(lst->next, c, pun);
}
