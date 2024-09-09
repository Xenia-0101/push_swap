/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/09 18:56:31 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
15 1 44 18 3 5 7 22 0 -5 70

Map state: 0
pb pb pb rrb pb rrb pb pb pb rrb rrb rrb pb rra sa ra pa pa pa ra ra ra pa rra rra rra pa pa pa pa
0	1
1	3
2	5
3	7
4	15
5	18
6	22
7	44
8	70
9	-5
10	0

 */
#include "push_swap.h"

void	ft_get_pos(t_stack *stack, int cv, int *pi, int *pv)
{
	if (cv > stack->max || cv < stack->min)
	{
		*pv = stack->max;
		*pi = ft_dlstiter_v(stack->lst, *pv);
	}
	else
	{
		*pv = stack->min;
		*pi = 0;
		ft_dlstiter_high_low(stack->lst, cv, pv, pi);
	}
}

void ft_first_to_b(t_map **map, t_stack *stack_a, t_stack *stack_b)
{
	t_dlist *temp;
	int curr_v;
	int push_v;
	int push_i;

	stack_a = (*map)->stack_a;
	stack_b = (*map)->stack_b;
	temp = stack_a->lst;

	while (stack_a->size > 3)
	{
		curr_v = temp->value;
		ft_get_pos(stack_b, curr_v, &push_i, &push_v);
		temp->ipo = push_i;
		ft_calc_act_big(map, &temp, temp->index, push_i);
		ft_calc_pun_big(map, &temp, temp->index, push_i);
		// only do the act if it is cheap
		ft_do_act_big(map, temp->pun);
		temp = temp->next;
		ft_pb(map);
	}
}

void ft_sort_big(t_map **map)
{
	int curr_v;
	int max_i;
	int temp_v;
	int cost;
	int push_v;
	int push_i;
	t_dlist *temp;
	t_stack *stack_a;
	t_stack *stack_b;

	ft_pb(map);
	ft_pb(map);
	ft_first_to_b(map, (*map)->stack_a, (*map)->stack_b);


	stack_a = (*map)->stack_a;
	stack_b = (*map)->stack_b;
	temp = stack_a->lst;

	ft_sort_3(map);

	temp = stack_b->lst;
	while (stack_b->size > 0)
	{
		curr_v = temp->value;
		// printf("* value: %d\n", curr_v);

		if (curr_v > stack_a->max || curr_v < stack_a->min)
		{
			push_v = stack_a->min;
			push_i = ft_dlstiter_v(stack_a->lst, push_v);
		}
		else
		{
			push_v = stack_a->max;
			push_i = 0;
			ft_dlstiter_low_high(stack_a->lst, curr_v, &push_v, &push_i);
		}
		temp->ipo = push_i;
		// printf("\tpush v: %d  push i: %d\n", push_v, temp->ipo);

		// calculate conf
		ft_calc_act_big(map, &temp, push_i, temp->index);
		// printf("\t\tconf: %d\tcost: %d\n", temp->conf, temp->cost);
		ft_calc_pun_big(map, &temp, push_i, temp->index);
		// ft_print_pun(temp->pun);

		// TODO: To be optimised
		ft_do_act_big(map, temp->pun);
		temp = temp->next;
		ft_pa(map);
	}
	push_i = ft_dlstiter_v(stack_a->lst, stack_a->min);
	if (push_i > stack_a->size / 2)
		ft_ra_x(map, push_i);
	else
		ft_rra_x(map, push_i);
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
	printf("\n");
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
	ft_free_map(map);
	exit(0);
}

