/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:29:01 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 10:31:24 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_dlstdelone(*lst);
		*lst = temp;
	}
}
