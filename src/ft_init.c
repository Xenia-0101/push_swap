/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:47:04 by xenia             #+#    #+#             */
/*   Updated: 2024/09/09 14:49:04 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_map(t_map **map, t_stack *stack_a);
void	ft_init_stack_a(t_stack **stack);
void	ft_init_stack_b(t_map **map);

/**
 * @brief Allocate memory for stack a
 * 			Set parameters to 0 or NULL
 *
 * 			TODO: 	Change to return NULL on failed allocation OR check after calling the function
 *
 * @param stack
 */
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
/**
 * @brief Allocate memory for stack b
 * 			Set initial min and max values to the stack a first value
 * 			Set the rest of the params to 0
 *
 * 			TODO: 	Change to return NULL on failed allocation OR check after calling the function
 *
 * @param map
 */
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
/**
 * @brief Allocate memory for map
 * 			Set stack a parameter
 * 			Set min, max and size to correspond to the stack a
 * 			Set else to 0
 *
 * 			TODO: 	Change to return NULL on failed allocation OR check after calling the function
 *
 * @param map
 * @param stack_a
 */
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
