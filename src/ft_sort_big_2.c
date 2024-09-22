/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 07:47:12 by xenia             #+#    #+#             */
/*   Updated: 2024/09/22 13:22:59 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_pos_a(t_stack *stack, int cv, int *pi, int *pv);
static void	ft_set_pun_a(t_map **map, t_stack *st, t_dlist **t1, t_dlist **t2);
static void	ft_calc_algo(t_map **map, t_dlist **t1, t_dlist **t2);
void		ft_sort_big_2(t_map **map, t_stack *stack_b);

static void	ft_get_pos_a(t_stack *stack, int cv, int *pi, int *pv)
{
	if (cv > stack->max || cv < stack->min)
	{
		*pv = stack->min;
		ft_dlstiter_v_last(stack->lst, *pv, pi);
	}
	else
	{
		*pv = stack->max;
		*pi = 0;
		ft_dlstiter_low_high(stack->lst, cv, pv, pi);
	}
}

static void	ft_set_pun_a(t_map **map, t_stack *st, t_dlist **t1, t_dlist **t2)
{
	if (((*t1)->index == 0 && (*t1)->cost == 0)
		|| ((*t1)->cost == (*t1)->index))
	{
		ft_pun_rotate(map, (*t1)->pun);
		ft_pa(map);
		(*t1) = st->lst;
		(*t2) = ft_dlstlast(st->lst);
	}
	else if ((*t2)->cost == st->size - 1)
	{
		ft_pun_rotate(map, (*t2)->pun);
		ft_pa(map);
		(*t1) = st->lst;
		(*t2) = ft_dlstlast(st->lst);
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

	while ((*t1) && t2 && (*map)->stack_b->size > 0)
	{
		curr_v = (*t1)->value;
		ft_get_pos_a((*map)->stack_a, curr_v, &push_i, &push_v);
		(*t1)->ipo = push_i;
		ft_calc_conf(map, t1, push_i, (*t1)->index);
		ft_calc_pun(map, t1, push_i, (*t1)->index);
		cv2 = (*t2)->value;
		ft_get_pos_a((*map)->stack_a, cv2, &push_i, &push_v);
		(*t2)->ipo = push_i;
		ft_calc_conf(map, t2, push_i, (*t2)->index);
		ft_calc_pun(map, t2, push_i, (*t2)->index);
		ft_set_pun_a(map, (*map)->stack_b, t1, t2);
	}
}

void	ft_sort_big_2(t_map **map, t_stack *stack_b)
{
	t_dlist	*t1;
	t_dlist	*t2;
	int		curr_v;

	t1 = stack_b->lst;
	t2 = ft_dlstlast(stack_b->lst);
	while (stack_b->size > 0)
	{
		ft_calc_algo(map, &t1, &t2);
		if (stack_b->size > 0)
		{
			curr_v = stack_b->lst->cost;
			stack_b->ih[0] = stack_b->lst->pun[0];
			stack_b->ih[1] = stack_b->lst->pun[1];
			stack_b->ih[2] = stack_b->lst->pun[2];
			stack_b->ih[3] = stack_b->lst->pun[3];
			ft_dlstiter_cheap(stack_b->lst, &curr_v, stack_b->ih);
			ft_pun_rotate(map, stack_b->ih);
			ft_pa(map);
		}
		t1 = stack_b->lst;
		t2 = ft_dlstlast(stack_b->lst);
	}
}
