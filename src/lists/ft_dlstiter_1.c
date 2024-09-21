/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:07:00 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 16:30:07 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *));
void	ft_dlstiter_v_last(t_dlist *lst, int v, int *i);
int		ft_dlstiter_v_first(t_dlist *lst, int v);
void	ft_dlstiter_max(t_dlist *lst, int v, int *tv);
void	ft_dlstiter_min(t_dlist *lst, int v, int *tv);

/**
 * @brief Iterate list and apply function f on each list node.
 *
 * @param lst List to iterate
 * @param f Function to be called
 */
void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *))
{
	if (!lst || !f)
		return ;
	f(lst);
	if (lst->next)
		ft_dlstiter(lst->next, f);
}

/**
 * @brief	Iterate list, set value of i to the index
 * 			of the last node with the value of v.
 *
 * @param lst	List to iterate
 * @param v		Value to be found
 * @param i		Index of the node with value i
 */
void	ft_dlstiter_v_last(t_dlist *lst, int v, int *i)
{
	if (!lst)
		return ;
	if (lst->value == v)
	{
		*i = lst->index;
	}
	if (lst->next)
		ft_dlstiter_v_last(lst->next, v, i);
}

/**
 * @brief	Iterate list, set tv value as the maximum in the list.
 *
 * @param lst	List to iterate
 * @param v		Initial value (minimum in the list).
 * @param tv	Temporary value - new maximum.
 */
void	ft_dlstiter_max(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return ;
	if (lst->value > v && lst->value > *tv)
	{
		*tv = lst->value;
	}
	if (lst->next)
		ft_dlstiter_max(lst->next, v, tv);
}

/**
 * @brief	Find the lowest number in the list that is larger than v.
 *
 * @param lst	List to iterate
 * @param v		Value to compare against.
 * @param tv	Temporary value - lowest number larger than v.
 * @param ti	Temporary index - index of the tv.
 */
void	ft_dlstiter_min(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return ;
	if (lst->value < v && lst->value < *tv)
	{
		*tv = lst->value;
	}
	if (lst->next)
		ft_dlstiter_min(lst->next, v, tv);
}

/**
 * @brief	Iterate list and return the index of the node with value v.
 * 			Return -1 if no such node exists.
 *
 * @param lst	List to iterate
 * @param v		Value to compare against.
 */
int	ft_dlstiter_v_first(t_dlist *lst, int v)
{
	if (!lst)
		return (-1);
	if (lst->value > v)
	{
		return (lst->index);
	}
	if (lst->next)
		ft_dlstiter_v_first(lst->next, v);
	return (-1);
}
