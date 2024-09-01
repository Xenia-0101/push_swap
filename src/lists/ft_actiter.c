/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:05:57 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 09:20:16 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_actiter(t_act *act, void (*f)(int c, int t))
{
	if (!f || !act)
		return ;
	f(act->cost, act->type);
	if (act->next)
		ft_actiter(act->next, f);
}
