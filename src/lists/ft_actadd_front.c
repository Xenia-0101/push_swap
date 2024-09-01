/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:46:51 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 08:50:14 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_actadd_front(t_act **act, t_act *new)
{
	if (!act || !new)
		return ;
	if (!*act)
	{
		*act = new;
		return ;
	}
	new->next = *act;
	*act = new;
}
