/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/21 12:29:22 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_pos_b(t_stack *stack, int cv, int *pi, int *pv)
{
	if (cv > stack->max || cv < stack->min)
	{
		*pv = stack->max;
		ft_dlstiter_v_1(stack->lst, *pv, pi);
	}
	else
	{
		*pv = stack->min;
		*pi = 0;
		ft_dlstiter_high_low(stack->lst, cv, pv, pi);
	}
}

void ft_set_pun_b(t_map **map, t_stack *stack, t_dlist **temp, t_dlist **t2)
{
	if ((*temp)->index == 0)
	{
		if ((*temp)->cost == 0)
		{
			ft_do_act_big(map, (*temp)->pun);
			ft_pb(map);
			*temp = stack->lst;
			*t2 = ft_dlstlast(stack->lst);
		}
		else
		{
			(*temp) = (*temp)->next;
			(*t2) = (*t2)->prev;
		}
	}
	// else if ((*temp)->cost == (*temp)->index)
	// {
	// 	ft_do_act_big(map, (*temp)->pun);
	// 	ft_pb(map);
	// 	*temp = stack->lst;
	// 	*t2 = ft_dlstlast(stack->lst);
	// }
	// else if ((*t2)->cost == stack->size - 1)
	// {
	// 	printf("\n\nhere\n\n");
	// 	ft_do_act_big(map, (*t2)->pun);
	// 	ft_pb(map);
	// 	*temp = stack->lst;
	// 	*t2 = ft_dlstlast(stack->lst);
	// }
	else
	{
		(*temp) = (*temp)->next;
		(*t2) = (*t2)->prev;
	}
}
void ft_first_to_b(t_map **map, t_stack *stack_a, t_stack *stack_b)
{
	t_dlist *temp;
	t_dlist *t2;
	int curr_v;
	int cv2;
	int push_v;
	int push_i;

	stack_a = (*map)->stack_a;
	stack_b = (*map)->stack_b;
	temp = stack_a->lst;
	t2 = ft_dlstlast(stack_a->lst);
	while (stack_a->size > 3)
	{
		while (temp && t2 && stack_a->size > 3 && temp->index < stack_a->size / 2)
		{
			curr_v = temp->value;
			ft_get_pos_b(stack_b, curr_v, &push_i, &push_v);
			temp->ipo = push_i;
			ft_calc_act_big(map, &temp, temp->index, push_i);
			ft_calc_pun_big(map, &temp, temp->index, push_i);

			cv2 = t2->value;
			ft_get_pos_b(stack_b, cv2, &push_i, &push_v);
			t2->ipo = push_i;
			ft_calc_act_big(map, &t2, t2->index, push_i);
			ft_calc_pun_big(map, &t2, t2->index, push_i);

			ft_set_pun_b(map, stack_a, &temp, &t2);
		}
		if (stack_a->size != 3)
		{
			curr_v = stack_a->lst->cost;
			stack_a->ih[0] = stack_a->lst->pun[0];
			stack_a->ih[1] = stack_a->lst->pun[1];
			stack_a->ih[2] = stack_a->lst->pun[2];
			stack_a->ih[3] = stack_a->lst->pun[3];
			ft_dlstiter_cheap(stack_a->lst, &curr_v, stack_a->ih);
			ft_do_act_big(map, stack_a->ih);
			ft_pb(map);
		}
		temp = stack_a->lst;
		t2 = ft_dlstlast(stack_a->lst);
	}
}

void	ft_get_pos_a(t_stack *stack, int cv, int *pi, int *pv)
{
	if (cv > stack->max || cv < stack->min)
	{
		*pv = stack->min;
		ft_dlstiter_v_1(stack->lst, *pv, pi);
	}
	else
	{
		*pv = stack->max;
		*pi = 0;
		ft_dlstiter_low_high(stack->lst, cv, pv, pi);
	}
}
void ft_set_pun_a(t_map **map, t_stack *stack, t_dlist **temp, t_dlist **t2)
{
	if ((*temp)->index == 0 && (*temp)->cost == 0)
	{
		ft_do_act_big(map, (*temp)->pun);
		ft_pa(map);
		(*temp) = stack->lst;
		(*t2) = ft_dlstlast(stack->lst);
	}
	else if ((*temp)->cost == (*temp)->index)
	{
		ft_do_act_big(map, (*temp)->pun);
		ft_pa(map);
		(*temp) = stack->lst;
		(*t2) = ft_dlstlast(stack->lst);
	}
	else if ((*t2)->cost == stack->size - 1)
	{
		ft_do_act_big(map, (*t2)->pun);
		ft_pa(map);
		(*temp) = stack->lst;
		(*t2) = ft_dlstlast(stack->lst);
	}
	else
	{
		(*temp) = (*temp)->next;
		(*t2) = (*t2)->prev;
	}

}

void ft_back_to_a(t_map **map, t_stack *stack_a, t_stack *stack_b)
{
	t_dlist *temp;
	t_dlist *t2;
	int curr_v;
	int cv2;
	int push_v;
	int push_i;

	temp = stack_b->lst;
	t2 = ft_dlstlast(stack_b->lst);
	while (stack_b->size > 0)
	{
		while (temp && t2 && stack_b->size > 0)
		{
			curr_v = temp->value;
			ft_get_pos_a(stack_a, curr_v, &push_i, &push_v);
			temp->ipo = push_i;
			ft_calc_act_big(map, &temp, push_i, temp->index);
			ft_calc_pun_big(map, &temp, push_i, temp->index);

			cv2 = t2->value;
			ft_get_pos_a(stack_a, cv2, &push_i, &push_v);
			t2->ipo = push_i;
			ft_calc_act_big(map, &t2, push_i, t2->index);
			ft_calc_pun_big(map, &t2, push_i, t2->index);

			ft_set_pun_a(map, stack_b, &temp, &t2);
		}
		if (stack_b->size > 0)
		{
			curr_v = stack_b->lst->cost;
			stack_b->ih[0] = stack_b->lst->pun[0];
			stack_b->ih[1] = stack_b->lst->pun[1];
			stack_b->ih[2] = stack_b->lst->pun[2];
			stack_b->ih[3] = stack_b->lst->pun[3];
			ft_dlstiter_cheap(stack_b->lst, &curr_v, stack_b->ih);
			ft_do_act_big(map, stack_b->ih);
			ft_pa(map);
		}
		temp = stack_b->lst;
		t2 = ft_dlstlast(stack_b->lst);
	}
}

void ft_sort_big(t_map **map)
{
	int min_i;
	t_stack *stack_a;

	stack_a = (*map)->stack_a;
	ft_pb(map);
	ft_pb(map);
	ft_first_to_b(map, stack_a, (*map)->stack_b);
	ft_sort_3(map);
	ft_back_to_a(map, stack_a, (*map)->stack_b);

	min_i = 0;
	ft_dlstiter_v_1(stack_a->lst, stack_a->min, (int *)&min_i);
	if (min_i < stack_a->size / 2)
		ft_ra_x(map, min_i, 1);
	else
		ft_rra_x(map, stack_a->size - min_i, 1);
}

void ft_sort(t_map **map)
{
	ft_init_stack_b(map);
	if ((*map)->size == 3)
		ft_sort_3(map);
	else if ((*map)->size == 4)
		ft_sort_4(map);
	else if ((*map)->size == 5)
		ft_sort_big(map);
	else
		ft_sort_big(map);
	ft_free_map(map);
	exit(0);
}

