/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:48:51 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 15:45:03 by xenia            ###   ########.fr       */
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
	printf("free stack\n");
	ft_dlstclear(&(*stack)->lst);
	printf("dlist is cleared\n");
	ft_free_split((*stack)->ph, (*stack)->size);
	(*stack)->max = 0;
	(*stack)->min = 0;
	(*stack)->size = 0;
	(*stack)->cheap = 0;
	printf("vals set to 0\n");
	free(*stack);
	printf("all done\n");
}

