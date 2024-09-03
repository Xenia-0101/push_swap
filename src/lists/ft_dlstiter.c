/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:07:00 by xenia             #+#    #+#             */
/*   Updated: 2024/09/03 23:35:46 by xenia            ###   ########.fr       */
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
	write(1, "No such index found\n", 20);
}

size_t	ft_dlstiter_v(t_dlist *lst, size_t v)
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
