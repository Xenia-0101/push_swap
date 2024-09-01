/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:50:37 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 08:53:19 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_actadd_back(t_act **act, t_act *new)
{
	t_act *temp;

	if (!act || !new)
		return ;
	if (!*act)
	{
		*act = new;
		return ;
	}
	temp = *act;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}
