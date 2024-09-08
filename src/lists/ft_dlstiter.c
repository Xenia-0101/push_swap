/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:07:00 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 10:59:28 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *))
{
	if (!lst || !f)
		return ;
	f(lst);
	if (lst->next)
		ft_dlstiter(lst->next, f);
}

void	ft_dlstiter_i(t_dlist *lst, size_t i, void (*f)(t_dlist *))
{
	if (!lst || !f)
		return ;
	if (lst->index == i)
	{
		f(lst);
		return ;
	}
	if (lst->next)
		ft_dlstiter_i(lst->next, i, f);
}

size_t	ft_dlstiter_v(t_dlist *lst, int v)
{
	if (!lst)
		return (-1);
	if (lst->value == v)
	{
		return (lst->index);
	}
	if (lst->next)
		ft_dlstiter_v(lst->next, v);
}
/// @brief Iterate list and find next lower value
/// @param lst
/// @param v	value to be pushed
/// @param tv	temporary value to push above
/// @return
size_t	ft_dlstiter_v_2(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return (-1);
	if (lst->value < v && lst->value > *tv)
	{
		*tv = lst->value;
		return (lst->index);
	}
	if (lst->next)
		ft_dlstiter_v_2(lst->next, v, tv);
}

size_t	ft_dlstiter_v_2_max(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return (-1);
	if (lst->value < v && lst->value > *tv)
	{
		*tv = lst->value;
		return (lst->index);
	}
	if (lst->next)
		ft_dlstiter_v_2_max(lst->next, v, tv);
}

void	ft_dlstiter_2_max(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return ;
	if (lst->value > v && lst->value > *tv)
	{
		*tv = lst->value;
	}
	if (lst->next)
		ft_dlstiter_2_max(lst->next, v, tv);
}

size_t	ft_dlstiter_v_3(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return (-1);
	if (lst->value > v && lst->value < *tv)
	{
		*tv = lst->value;
		return (lst->index);
	}
	if (lst->next)
		ft_dlstiter_v_3(lst->next, v, tv);
}

// get highest number that is lower than v and
// set the value and index to tv and ti
// used in sort big --> push to b
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

// get lowest number that is higher than v
// set the value and index to tv and ti
// used in sort big --> push to a
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


void	ft_dlstiter_3_min(t_dlist *lst, int v, int *tv)
{
	if (!lst)
		return ;
	if (lst->value < v && lst->value < *tv)
	{
		*tv = lst->value;
	}
	if (lst->next)
		ft_dlstiter_3_min(lst->next, v, tv);
}

size_t	ft_dlstiter_v_4(t_dlist *lst, int v)
{
	if (!lst)
		return (-1);
	if (lst->value > v)
	{
		return (lst->index);
	}
	if (lst->next)
		ft_dlstiter_v_4(lst->next, v);
}
