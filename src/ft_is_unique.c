/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:16:55 by xenia             #+#    #+#             */
/*   Updated: 2024/09/22 14:18:18 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_compare_tab(int q, int r, int *tab, int len);
static int	ft_check_unique(t_stack **stack, int *tab);
static int	ft_check_odd(t_stack **stack, int *tab);
int			ft_is_unique(t_stack **stack);

/**
 * @brief Check if "q" or "r" are found in tab
 *
 * @param q		integer value
 * @param r		integer value
 * @param tab	an array of integers
 * @param len	count of elements in tab
 * @return int	1 if not fount, else 0
 */
static int	ft_compare_tab(int q, int r, int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (q == tab[i] || r == tab[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief	Having stack with odd size, check if the value
 * 				of the middle node is found in tab
 * 			Get hold of the middle node
 * 			Get the size of the tab decreased by one
 * 			Check the middle.vale and middle.next.value are different
 * 			Check the middle.value and middle.next.value are not found in tab
 *
 * 			len = (*stack)->size - 2;
 * 			The tab contains all but the middle elements (thus -1)
 * 				and the last element is equal to middle.next.value (thus -2)
 *
 * @param stack
 * @param tab
 * @return int
 */
static int	ft_check_odd(t_stack **stack, int *tab)
{
	t_dlist	*mid;
	int		len;

	mid = ft_dlstat_i((*stack)->lst, (*stack)->size / 2);
	len = (*stack)->size - 2;
	if (mid->value == mid->next->value
		|| !ft_compare_tab(mid->value, mid->next->value, tab, len))
		return (0);
	return (1);
}

/**
 * @brief	Check if numbers in stack are unique
 *			Initialise "front" and "back" to the first and last node.value
 *			Check that the front.value and back.value are different
 *			Check that the front.value or back.value are not in tab
 *			Store front.value and back.value in tab and move tab position by 2
 *			Move front to the next node
 *			Move back to the previous node
 *
 * @param stack	The stack to be checked
 * @param tab	The array of numbers to be checked
 * @return int	1 if unique, else 0
 */
static int	ft_check_unique(t_stack **stack, int *tab)
{
	t_dlist	*front;
	t_dlist	*back;
	int		i;

	front = (*stack)->lst;
	back = ft_dlstlast((*stack)->lst);
	i = 0;
	while (front->index != (*stack)->size / 2)
	{
		if (front->value == back->value)
			return (0);
		if (!ft_compare_tab(front->value, back->value, tab, i))
			return (0);
		tab[i] = front->value;
		tab[i + 1] = back->value;
		front = front->next;
		back = back->prev;
		i += 2;
	}
	return (1);
}

/**
 * @brief	Check if numbers in stack are unique
 * 			Allocate memory for temporary variable "tab"
 * 				Exit program on fail
 * 			Call ft_check_unique
 * 			If size of stack is odd, call ft_check_odd
 * 			Free tab
 * 			Return res
 *
 * @param stack	The stack to be checked
 * @return int	1 if unique, else 0
 */
int	ft_is_unique(t_stack **stack)
{
	int	*tab;
	int	res;

	tab = ft_calloc((*stack)->size, sizeof (int));
	if (!tab)
	{
		ft_free_stack(stack);
		free(tab);
		exit(1);
	}
	res = ft_check_unique(stack, tab);
	if (res && (*stack)->size % 2)
		res = ft_check_odd(stack, tab);
	free(tab);
	return (res);
}
