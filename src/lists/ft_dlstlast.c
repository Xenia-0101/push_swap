/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:16:43 by xenia             #+#    #+#             */
/*   Updated: 2024/09/09 16:09:44 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	t_dlist	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_dlist	*ft_dlstat_i(t_dlist *lst, int i)
{
	t_dlist	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
	{
		if (temp->index == i)
			return (temp);
		temp = temp->next;
	}
	return (temp);
}
