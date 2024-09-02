/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:47:04 by xenia             #+#    #+#             */
/*   Updated: 2024/09/02 09:54:49 by xvislock         ###   ########.fr       */
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

void	ft_init_stack_b(t_map **map)
{
	t_stack	**stack;

	stack = &(*map)->stack_b;
	*stack = (t_stack *)ft_calloc(1, sizeof (t_stack));
	if (!*stack)
		return ;
	(*stack)->lst = NULL;
	(*stack)->ph = NULL;
	(*stack)->size = 0;
	(*stack)->min = (*map)->stack_a->lst->value;
	(*stack)->max = (*map)->stack_a->lst->value;
	(*stack)->cheap = 0;
}

void	ft_init_map(t_map **map, t_stack *stack_a)
{
	*map = (t_map *)ft_calloc(1, sizeof (t_map));
	if (!*map)
		return ;
	(*map)->stack_a = stack_a;
	(*map)->stack_b = NULL;
	(*map)->acts = NULL;
	(*map)->size = stack_a->size;
	(*map)->min = stack_a->min;
	(*map)->max = stack_a->max;
	(*map)->state = 0;
}
