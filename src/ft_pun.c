/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:49:36 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 16:55:56 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculate the cheapest action
// return the configuration number (1 - 4)
// !!!!
// the cost and config are saved to st_a, ia -> the first passed stack
// !!!!
int	ft_calc_act(t_stack *st_a, t_stack *st_b, int ia, int ib)
{
	int	res[4];
	int	i;
	int	v;

	res[0] = ft_max(ia, ib);
	res[1] = ia + st_b->size - ib;
	res[2] = st_a->size - ia + ib;
	res[3] = ft_max(st_a->size - ia, st_b->size - ib);

	return (ft_min_tab(res, 4));
}

int	ft_calc_act_big(t_map **map, t_dlist **lst, int ia, int ib)
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

void	ft_calc_pun_big(t_map **map, t_dlist **lst, int ia, int ib)
{
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

void	ft_do_act_big(t_map **map, int pun[4])
{
	ft_ra_x(map, pun[0]);
	ft_rra_x(map, pun[1]);
	ft_rb_x(map, pun[2]);
	ft_rrb_x(map, pun[3]);
}
