/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:48:51 by xenia             #+#    #+#             */
/*   Updated: 2024/09/09 14:59:07 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_split(char **str, int len);
void		ft_free_map(t_map **map);
void		ft_free_stack(t_stack **stack);

/**
 * @brief If str does not exist, return
 * 			Iterate str and free each *str
 * 			Free str
 *
 * @param str	String pointer to be freed
 * @param len	Number of strings in the pointer
 */
static void	ft_free_split(char **str, int len)
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
/**
 * @brief 	Clear each node in dlist using ft_dlstclear function
 * 			Free placeholder (stack.ph) using ft_free_split function
 * 			Set all params to 0
 * 			Free stack
 *
 * @param stack The stack to be freed
 */
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
/**
 * @brief 	If stack a or stack b exist, free them using ft_free_stack function
 *			Set all params to 0
			Free map
 *
 * @param map
 */
void	ft_free_map(t_map **map)
{
	if ((*map)->stack_a)
		ft_free_stack(&(*map)->stack_a);
	if ((*map)->stack_b)
		ft_free_stack(&((*map)->stack_b));
	(*map)->size = 0;
	(*map)->min = 0;
	(*map)->max = 0;
	(*map)->state = 0;
	free(*map);
}
