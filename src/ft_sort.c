/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/03 23:56:35 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_sort_3(t_map **map)
{
	t_stack *stack;
	int	max;
	size_t max_i;

	stack = (*map)->stack_a;
	max = (*map)->stack_a->max;
	max_i = ft_dlstiter_v((*map)->stack_a->lst, (*map)->stack_a->max);
	if (max_i == 1)
	{
		ft_rra(map);
		write(1, "rra\n", 4);
	}
	if (max_i == 0)
	{
		ft_ra(map);
		write(1, "ra\n", 4);
	}
	if (stack->min != stack->lst->value)
	{
		ft_sa(map);
		write(1, "sa\n", 3);
	}
}

void ft_sort_4(t_map **map)
{
// init stack b
// pb
// sort a
// pa --- find correct position
}

void ft_sort_5(t_map **map)
{

}

void ft_sort_big(t_map **map)
{

}

void ft_sort(t_map **map)
{
	if ((*map)->size == 3)
		ft_sort_3(map);
	else if ((*map)->size == 4)
		ft_sort_4(map);
	else if ((*map)->size == 5)
		ft_sort_5(map);
	else
		ft_sort_big(map);
	printf("Sorting\n");
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
}

