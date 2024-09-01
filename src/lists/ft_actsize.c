/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:54:52 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 09:02:12 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_actsize(t_act *act)
{
	t_act	*temp;
	size_t	i;

	i = 0;
	if (!act)
		return (i);
	temp = act;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
