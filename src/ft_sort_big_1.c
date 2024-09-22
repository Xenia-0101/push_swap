/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 06:36:18 by xenia             #+#    #+#             */
/*   Updated: 2024/09/22 08:36:24 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_pos_b(t_stack *stack, int cv, int *pi, int *pv)
{
	if (cv > stack->max || cv < stack->min)
	{
		*pv = stack->max;
		ft_dlstiter_v_last(stack->lst, *pv, pi);
	}
	else
	{
		*pv = stack->min;
		*pi = 0;
		ft_dlstiter_high_low(stack->lst, cv, pv, pi);
	}
}

static void	ft_set_pun_b(t_map **map, t_stack *st, t_dlist **t1, t_dlist **t2)
{
	if ((*t1)->index == 0)
	{
		if ((*t1)->cost == 0)
		{
			ft_pun_rotate(map, (*t1)->pun);
			ft_pb(map);
			*t1 = st->lst;
			*t2 = ft_dlstlast(st->lst);
		}
		else
		{
			(*t1) = (*t1)->next;
			(*t2) = (*t2)->prev;
		}
	}
	else
	{
		(*t1) = (*t1)->next;
		(*t2) = (*t2)->prev;
	}
}

static void	ft_calc_algo(t_map **map, t_dlist **t1, t_dlist **t2)
{
	int	curr_v;
	int	cv2;
	int	push_v;
	int	push_i;

	while ((*t1) && t2 && (*map)->stack_a->size > 3
		&& (*t1)->index < (*map)->stack_a->size / 2)
	{
		curr_v = (*t1)->value;
		ft_get_pos_b((*map)->stack_b, curr_v, &push_i, &push_v);
		(*t1)->ipo = push_i;
		ft_calc_conf(map, t1, (*t1)->index, push_i);
		ft_calc_pun(map, t1, (*t1)->index, push_i);
		cv2 = (*t2)->value;
		ft_get_pos_b((*map)->stack_b, cv2, &push_i, &push_v);
		(*t2)->ipo = push_i;
		ft_calc_conf(map, t2, (*t2)->index, push_i);
		ft_calc_pun(map, t2, (*t2)->index, push_i);
		ft_set_pun_b(map, (*map)->stack_a, t1, t2);
	}
}

void	ft_sort_big_1(t_map **map, t_stack *stack_a, t_stack *stack_b)
{
	t_dlist	*temp;
	t_dlist	*t2;
	int		curr_v;

	stack_a = (*map)->stack_a;
	stack_b = (*map)->stack_b;
	temp = stack_a->lst;
	t2 = ft_dlstlast(stack_a->lst);
	while (stack_a->size > 3)
	{
		ft_calc_algo(map, &temp, &t2);
		if (stack_a->size != 3)
		{
			curr_v = stack_a->lst->cost;
			stack_a->ih[0] = stack_a->lst->pun[0];
			stack_a->ih[1] = stack_a->lst->pun[1];
			stack_a->ih[2] = stack_a->lst->pun[2];
			stack_a->ih[3] = stack_a->lst->pun[3];
			ft_dlstiter_cheap(stack_a->lst, &curr_v, stack_a->ih);
			ft_pun_rotate(map, stack_a->ih);
			ft_pb(map);
		}
		temp = stack_a->lst;
		t2 = ft_dlstlast(stack_a->lst);
	}
}
