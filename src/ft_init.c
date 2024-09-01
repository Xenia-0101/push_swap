/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:47:04 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 15:47:28 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack_a(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(1, sizeof (t_stack));
	if (!*stack)
		return ;
	(*stack)->lst = NULL;
	(*stack)->ph = NULL;
	(*stack)->size = 0;
	(*stack)->min = 0;
	(*stack)->max = 0;
	(*stack)->cheap = 0;
}
