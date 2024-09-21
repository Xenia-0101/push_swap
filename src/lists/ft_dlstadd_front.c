/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:04:10 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 12:25:51 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_incr_index(t_dlist *lst)
{
	if (!lst)
		return ;
	lst->index++;
}

// static void	ft_decr_index(t_dlist *lst)
// {
// 	if (!lst)
// 		return ;
// 	lst->index--;
// }

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_dlstiter(*lst, &ft_incr_index);
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
