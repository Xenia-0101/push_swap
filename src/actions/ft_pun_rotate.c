/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pun_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:46:55 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 20:56:47 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_ra_rb(t_map **map, int i, int j)
// {
// 	int	ra_c;
// 	int	rb_c;
// 	int	rr_c;

// 	ft_ra_x(map, i, 0);
// 	ft_rb_x(map, j, 0);
// 	if (i > j)
// 	{
// 		ra_c = i - j;
// 		rb_c = 0;
// 		rr_c = j;
// 	}
// 	else
// 	{
// 		ra_c = 0;
// 		rb_c = j - i;
// 		rr_c = i;
// 	}
// 	ft_write_rr(ra_c, rb_c, rr_c);
// }

/**
 * @brief Perform rotations based on pun values
 *
 * @param map
 * @param pun lst.pun
 */
void	ft_pun_rotate(t_map **map, int pun[4])
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
		// ft_ra_rb(map, pun[0], pun[2]);

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

