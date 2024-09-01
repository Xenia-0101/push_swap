/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:41:02 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 09:20:23 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef struct s_act
{
	struct s_act	*next;
	size_t			cost;
	int				type;
}	t_act;
*/

t_act	*ft_actnew(size_t cost, int type)
{
	t_act	*act;

	act = (t_act *)ft_calloc(1, sizeof (t_act));
	if (!act)
		return (NULL);
	act->cost = cost;
	act->type = type;
	act->next = NULL;
	return (act);
}
