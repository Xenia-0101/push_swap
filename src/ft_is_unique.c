/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:16:55 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 11:31:43 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_unique_odd(t_stack **stack, int *tab)
{
	int		i;
	int		j;
	t_dlist	*front;
	t_dlist	*back;

	i = 0;
	front = (*stack)->lst;
	back = ft_dlstlast(front);
	while (front->index != (*stack)->size / 2)
	{
		if (front->value == back->value)
		{
			return (0);
		}
		j = 0;
		while (j < (front->index) * 2)
		{
			if (front->value == tab[j] || back->value == tab[j])
			{
				return (0);
			}
			j++;
		}
		tab[i] = front->value;
		tab[i + 1] = back->value;
		i += 2;
		front = front->next;
		back = back->prev;
	}
	i--;
	while (i > -1)
	{
		if (front->value == tab[i])
		{
			return (0);
		}
		i--;
	}
	return (1);
}

static int	ft_unique_even(t_stack **stack, int *tab)
{
	t_dlist	*front;
	t_dlist	*back;
	int		i;
	int		j;

	front = (*stack)->lst;
	back = ft_dlstlast((*stack)->lst);
	i = 0;
	while (front->index != (*stack)->size / 2)
	{
		if (front->value == back->value)
			return (0);
		j = 0;
		while (j < (front->index + 1) / 2)
		{
			if (front->value == tab[j] || back->value == tab[j])
				return (0);
			j++;
		}
		tab[i] = front->value;
		tab[i + 1] = back->value;
		i += 2;
		front = front->next;
		back = back->prev;
	}
	return (1);
}

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
	if ((*stack)->size % 2)
		res = ft_unique_odd(stack, tab);
	else
		res = ft_unique_even(stack, tab);
	free(tab);
	return (res);
}
