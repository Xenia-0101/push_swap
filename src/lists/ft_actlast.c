/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:00:18 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 09:04:59 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_act	*ft_actlast(t_act *act)
{
	t_act	*temp;

	if (!act)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
