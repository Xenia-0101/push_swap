/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:48:51 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 23:19:08 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str, int len)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_stack **stack)
{
	ft_dlstclear(&(*stack)->lst);
	ft_free_split((*stack)->ph, (*stack)->size);
	(*stack)->max = 0;
	(*stack)->min = 0;
	(*stack)->size = 0;
	(*stack)->cheap = 0;
	free(*stack);
}

void	ft_free_map(t_map **map)
{
	if ((*map)->stack_a)
		ft_free_stack(&(*map)->stack_a);
	if ((*map)->stack_b)
		ft_free_stack(&((*map)->stack_b));
	// if ((*map)->acts)							// TODO
	// 	ft_free_acts(((*map)->acts));
	(*map)->size = 0;
	(*map)->min = 0;
	(*map)->max = 0;
	(*map)->state = 0;
	free(*map);
}

