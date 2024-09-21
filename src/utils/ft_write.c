/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:44:02 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 20:44:42 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
