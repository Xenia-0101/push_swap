/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:49:36 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 21:26:55 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reset_pun(int pun[4]);
int			ft_calc_conf(t_map **map, t_dlist **lst, int ia, int ib);
void		ft_calc_pun(t_map **map, t_dlist **lst, int ia, int ib);

/**
 * @brief Reset values of pun to 0.
 *
 * @param pun int[4] array
 */
static void ft_reset_pun(int pun[4])
{
	pun[0] = 0;
	pun[1] = 0;
	pun[2] = 0;
	pun[3] = 0;
}

/**
 * @brief	Calculate the cost of each action configuration to get
 * 			two elements to the top of their stack
 * 			Set lst.conf and lst.cost to the cheapest option
 *
 * 			Possible configurations:
 * 				0: ra  && rb
 * 				1: rra && rb
 * 				2: ra  && rrb
 * 				3: rra && rrb
 * 			The cost of each configuration is calculated based on
 * 			the size of stacks and positions of nodes.
 *
 * @param map
 * @param lst	List we want to push from
 * @param ia	Index of the node in stack a
 * @param ib	Index of the node in stack b
 * @return int	Reference to the configuration (0 - 3)
 */
int	ft_calc_conf(t_map **map, t_dlist **lst, int ia, int ib)
{
	int	res[4];
	int	sa;
	int	sb;

	sa = (*map)->stack_a->size;
	sb = (*map)->stack_b->size;

	res[0] = ft_max(ia, ib);
	res[1] = ia + sb - ib;
	res[2] = sa - ia + ib;
	res[3] = ft_max(sa - ia, sb - ib);
	(*lst)->conf = ft_min_tab(res, 4);
	(*lst)->cost = res[(*lst)->conf];
	return (ft_min_tab(res, 4));
}
/**
 * @brief Calculate lst.pun knowing the lst.conf,
 * 		size of lst in both stacks and the position of each node
 *
 * 		The meaning of lst.pun:
 * 			lst.pun[0] - count of ra operations
 * 			lst.pun[1] - count of rra operations
 * 			lst.pun[2] - count of rb operations
 * 			lst.pun[3] - count of rrb operations
 *
 * @param map
 * @param lst	The list to be pushed from
 * @param ia	Index of the node in stack a
 * @param ib	Index of the node in stack b
 */
void	ft_calc_pun(t_map **map, t_dlist **lst, int ia, int ib)
{
	ft_reset_pun((*lst)->pun);
	if ((*lst)->conf == 0)
	{
		(*lst)->pun[0] = ia;
		(*lst)->pun[2] = ib;
	}
	else if ((*lst)->conf == 1)
	{
		(*lst)->pun[0] = ia;
		(*lst)->pun[3] = (*map)->stack_b->size - ib;
	}
	else if ((*lst)->conf == 2)
	{
		(*lst)->pun[1] = (*map)->stack_a->size - ia;
		(*lst)->pun[2] = ib;
	}
	else if ((*lst)->conf == 3)
	{
		(*lst)->pun[1] = (*map)->stack_a->size - ia;
		(*lst)->pun[3] = (*map)->stack_b->size - ib;
	}
}
