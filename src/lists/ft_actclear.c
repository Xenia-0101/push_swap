/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:17:30 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 09:20:04 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_actclear(t_act **act)
{
	t_act	*temp;

	while (*act)
	{
		temp = (*act)->next;
		ft_actdelone(*act);
		*act = temp;
	}
}
