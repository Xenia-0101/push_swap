/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:23:45 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 21:59:04 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dlstsize(t_dlist *lst)
{
	t_dlist	*temp;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
