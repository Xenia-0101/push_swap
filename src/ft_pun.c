/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pun.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 07:49:36 by xenia             #+#    #+#             */
/*   Updated: 2024/09/06 07:52:50 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// calculate the cheapest action
int ft_calc_act(t_stack *st_a, t_stack *st_b, int ia, int ib)
{
	int res[4];
	int i;
	int v;

	res[0] = ft_max(ia, ib);
	res[1] = ia + st_b->size - ib;
	res[2] = st_a->size - ia + ib;
	res[3] = ft_max(st_a->size - ia, st_b->size - ib);

	return (ft_min_tab(res, 4));
}

// knowing idx of elements to be pushed, calculate configuration
void ft_calc_pun(t_map **map, t_pun *pun, int ia, int ib)
{
	int sa = (int)(*map)->stack_a->size;
	int sb = (int)(*map)->stack_b->size;

	pun->v[0][0] = ia;
	pun->v[0][1] = 0;
	pun->v[0][2] = ib;
	pun->v[0][3] = 0;
	pun->v[1][0] = ia;
	pun->v[1][1] = 0;
	pun->v[1][2] = 0;
	pun->v[1][3] = sb - ib;
	pun->v[2][0] = 0;
	pun->v[2][1] = sa - ia;
	pun->v[2][2] = ib;
	pun->v[2][3] = 0;
	pun->v[3][0] = 0;
	pun->v[3][1] = sa - ia;
	pun->v[3][2] = 0;
	pun->v[3][3] = sb - ib;

}

void ft_copy_tab(int t1[4], int t2[4])
{
	t1[0] = t2[0];
	t1[1] = t2[1];
	t1[2] = t2[2];
	t1[3] = t2[3];
}

void ft_do_act(t_map **map, t_pun *pun, int r)
{
	int acts[4];

	ft_copy_tab(acts, pun->v[r]);
	printf("\n**%d %d %d %d\n", acts[0], acts[1], acts[2], acts[3]);
	ft_ra_x(map, acts[0]);
	ft_rb_x(map, acts[1]);
	ft_rra_x(map, acts[2]);
	ft_rrb_x(map, acts[3]);
}
void ft_redo_act(t_map **map, t_pun *pun, int r)
{
	int acts[4];

	ft_copy_tab(acts, pun->v[r]);
	printf("\n**%d %d %d %d\n", acts[0], acts[1], acts[2], acts[3]);
	ft_rra_x(map, acts[0]);
	ft_ra_x(map, acts[2]);
}

void ft_print_pun(t_pun pun)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			printf("%d\t", pun.v[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

