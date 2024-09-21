/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pun_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:46:55 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 21:59:49 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ra_rb(t_map **map, int i, int j)
{
	int	ra_c;
	int	rb_c;
	int	rr_c;

	ft_ra_x(map, i, 0);
	ft_rb_x(map, j, 0);
	if (i > j)
	{
		ra_c = i - j;
		rb_c = 0;
		rr_c = j;
	}
	else
	{
		ra_c = 0;
		rb_c = j - i;
		rr_c = i;
	}
	ft_write_rr(ra_c, rb_c, rr_c);
}

static void	ft_rra_rrb(t_map **map, int i, int j)
{
	int	ra_c;
	int	rb_c;
	int	rr_c;

	ft_rra_x(map, i, 0);
	ft_rrb_x(map, j, 0);
	if (i > j)
	{
		ra_c = i - j;
		rb_c = 0;
		rr_c = j;
	}
	else
	{
		ra_c = 0;
		rb_c = j - i;
		rr_c = i;
	}
	ft_write_rrr(ra_c, rb_c, rr_c);
}

/**
 * @brief Perform rotations based on pun values
 *
 * @param map
 * @param pun lst.pun
 */
void	ft_pun_rotate(t_map **map, int pun[4])
{
	if (pun[0] && pun[2])
	{
		ft_ra_rb(map, pun[0], pun[2]);
	}
	else if (pun[1] && pun[3])
	{
		ft_rra_rrb(map, pun[1], pun[3]);
	}
	else
	{
		ft_ra_x(map, pun[0], 1);
		ft_rra_x(map, pun[1], 1);
		ft_rb_x(map, pun[2], 1);
		ft_rrb_x(map, pun[3], 1);
	}
}
