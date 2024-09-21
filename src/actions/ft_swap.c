/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:02:30 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 13:03:51 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_map **map);
void	ft_sb(t_map **map);

/**
 * @brief Swap first two values in a.
 *
 * @param map
 */
void	ft_sa(t_map **map)
{
	int		val;
	t_dlist	*temp;

	if (!(*map)->stack_a->lst)
		return ;
	if (!(*map)->stack_a->lst->next)
		return ;
	temp = (*map)->stack_a->lst->next;
	val = (*map)->stack_a->lst->value;
	(*map)->stack_a->lst->value = temp->value;
	temp->value = val;
	write(1, "sa\n", 3);
}

/**
 * @brief Swap first two values in b.
 *
 * @param map
 */
void	ft_sb(t_map **map)
{
	int		val;
	t_dlist	*temp;

	if (!(*map)->stack_b->lst)
		return ;
	if (!(*map)->stack_b->lst->next)
		return ;
	temp = (*map)->stack_b->lst->next;
	val = (*map)->stack_b->lst->value;
	(*map)->stack_b->lst->value = temp->value;
	temp->value = val;
	write(1, "sb\n", 3);
}
