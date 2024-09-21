/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:26:09 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 12:19:31 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstdelone(t_dlist *lst)
{
	int	i;

	lst->ipo = 0;
	lst->cost = 0;
	lst->conf = 0;
	i = 0;
	while (i < 4)
	{
		lst->pun[i] = 0;
		i++;
	}
	lst->index = 0;
	lst->value = 0;
	free(lst);
}
