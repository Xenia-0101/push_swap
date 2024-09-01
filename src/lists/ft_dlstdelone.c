/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:26:09 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 10:41:39 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dlstdelone(t_dlist *lst)
{
	if (lst->acts)
		ft_actclear(&(lst->acts));
	lst->index = 0;
	lst->value = 0;
	free(lst);
}
