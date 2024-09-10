/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:49:36 by xenia             #+#    #+#             */
/*   Updated: 2024/09/10 20:52:34 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_calc_act_big(t_map **map, t_dlist **lst, int ia, int ib);
void	ft_calc_pun_big(t_map **map, t_dlist **lst, int ia, int ib);
void	ft_do_act_big(t_map **map, int pun[4]);

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
void	ft_calc_pun_big(t_map **map, t_dlist **lst, int ia, int ib)
{
	if ((*lst)->conf == 0)
	{
		(*lst)->pun[0] = ia;
		(*lst)->pun[1] = 0;
		(*lst)->pun[2] = ib;
		(*lst)->pun[3] = 0;
	}
	else if ((*lst)->conf == 1)
	{
		(*lst)->pun[0] = ia;
		(*lst)->pun[1] = 0;
		(*lst)->pun[2] = 0;
		(*lst)->pun[3] = (*map)->stack_b->size - ib;
	}
	else if ((*lst)->conf == 2)
	{
		(*lst)->pun[0] = 0;
		(*lst)->pun[1] = (*map)->stack_a->size - ia;
		(*lst)->pun[2] = ib;
		(*lst)->pun[3] = 0;
	}
	else if ((*lst)->conf == 3)
	{
		(*lst)->pun[0] = 0;
		(*lst)->pun[1] = (*map)->stack_a->size - ia;
		(*lst)->pun[2] = 0;
		(*lst)->pun[3] = (*map)->stack_b->size - ib;
	}
}

void	ft_write_rr(int ra_c, int rb_c, int rr_c)
{
	while (ra_c)
	{
		write(1, "ra\n", 3);
		ra_c--;
	}
	while (rb_c)
	{
		write(1, "rb\n", 3);
		rb_c--;
	}
	while (rr_c)
	{
		write(1, "rr\n", 3);
		rr_c--;
	}
}

void	ft_write_rrr(int ra_c, int rb_c, int rr_c)
{
	while (ra_c)
	{
		write(1, "rra\n", 4);
		ra_c--;
	}
	while (rb_c)
	{
		write(1, "rrb\n", 4);
		rb_c--;
	}
	while (rr_c)
	{
		write(1, "rrr\n", 4);
		rr_c--;
	}
}
/**
 * @brief Perform rotations based on pun values
 *
 * @param map
 * @param pun lst.pun
 */
void	ft_do_act_big(t_map **map, int pun[4])
{
	int temp_p[4];
	int ra_c;
	int rb_c;
	int rr_c;

	temp_p[0] = pun[0];
	temp_p[1] = pun[1];
	temp_p[2] = pun[2];
	temp_p[3] = pun[3];

	if (temp_p[0] && temp_p[2])	// if ra and rb
	{
		ft_ra_x(map, temp_p[0], 0);
		ft_rb_x(map, temp_p[2], 0);
		if (temp_p[0] > temp_p[2])
		{
			ra_c = temp_p[0] - temp_p[2];
			rb_c = 0;
			rr_c = temp_p[2];
		}
		else
		{
			ra_c = 0;
			rb_c = temp_p[2] - temp_p[0];
			rr_c = temp_p[0];
		}
		ft_write_rr(ra_c, rb_c, rr_c);

	}
	else if (temp_p[1] && temp_p[3]) // if rra and rrb
	{
		ft_rra_x(map, temp_p[1], 0);
		ft_rrb_x(map, temp_p[3], 0);
		if (temp_p[1] > temp_p[3])
		{
			ra_c = temp_p[1] - temp_p[3];
			rb_c = 0;
			rr_c = temp_p[3];
		}
		else
		{
			ra_c = 0;
			rb_c = temp_p[3] - temp_p[1];
			rr_c = temp_p[1];
		}
		ft_write_rrr(ra_c, rb_c, rr_c);
	}
	else
	{
		ft_ra_x(map, temp_p[0], 1);
		ft_rra_x(map, temp_p[1], 1);
		ft_rb_x(map, temp_p[2], 1);
		ft_rrb_x(map, temp_p[3], 1);
	}
}
