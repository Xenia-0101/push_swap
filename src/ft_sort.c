/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:44:48 by xenia             #+#    #+#             */
/*   Updated: 2024/09/05 12:25:47 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void ft_sort_3(t_map **map)
{
	t_stack *stack;
	int	max;
	size_t max_i;

	stack = (*map)->stack_a;
	max = (*map)->stack_a->max;

	printf("\nBefore 3\n\n");
	printf("size of a: %ld\n", stack->size);
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
	max_i = ft_dlstiter_v((*map)->stack_a->lst, (*map)->stack_a->max);
	printf("max i: %ld\n", max_i);
	if (max_i == 1)
	{
		ft_rra(map);
		write(1, "rra\n", 4);
	}
	if (max_i == 0)
	{
		ft_ra(map);
		write(1, "ra\n", 4);
	}
	printf("stack min: %d\tstack val: %d\n", stack->min, stack->lst->value);
	if (stack->min != stack->lst->value)
	{
		ft_sa(map);
		write(1, "sa\n", 3);
	}

	printf("\nAfter 3\n\n");
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
}

void ft_sort_4(t_map **map)
{
	printf("Ft sort 4\n");
	// pb
	printf("Size of a: %ld\n", (*map)->stack_a->size);
	ft_pb(map);
	write(1, "pb\n", 3);
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
	// sort a
	ft_sort_3(map);
	// pa --- find correct position (index above which to push -->next lowest)
		// if val is == to stack min -> pa
		// if val is == to stack max -> pa, ra
		// else iterate list by value
			// -- init temp var for the first element
			// -- if list val is < val to push && > temp var: reset temp var


	// problems with 0
	int val_b;
	val_b = (*map)->stack_b->lst->value;
	if (val_b < (*map)->stack_a->min)
	{
		ft_pa(map);
		write(1, "pa\n", 3);
	}
	else if (val_b > (*map)->stack_a->max)
	{
		ft_pa(map);
		write(1, "pa\n", 3);
		ft_ra(map);
		write(1, "ra\n", 3);
	}
	else
	{
		printf("iterate\n");
		size_t temp_i;
		printf("Size of a: %ld\n", (*map)->stack_a->size);
		// itterate sorted list and find first value that is larger
		temp_i = ft_dlstiter_v_4((*map)->stack_a->lst, val_b);
		printf("to push: %d\t... i: %ld\t\n", val_b, temp_i);
		if (temp_i == 0)
		{
			ft_pa(map);
			write(1, "pa\n", 3);
		}
		else if (temp_i == 1)
		{
			ft_ra(map);
			write(1, "ra\n", 3);
			ft_pa(map);
			write(1, "pa\n", 3);
			ft_rra(map);
			write(1, "rra\n", 4);
		}
		else
		{
			ft_rra(map);
			write(1, "ra\n", 3);
			ft_pa(map);
			write(1, "pa\n", 3);
			ft_rra(map);
			write(1, "rra\n", 4);
			ft_rra(map);
			write(1, "rra\n", 4);
		}
	}
	printf("\nAfter 4\n\n");
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);

}
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

void ft_sort_5(t_map **map)
{
	size_t temp_i;
	t_pun pun;
	int res;
	int val_b;

	printf("Sort 5\n");
	printf("Size of a: %ld\n\n", (*map)->stack_a->size);
	ft_pb(map);
	write(1, "pb\n", 3);
	ft_sort_4(map);
	// find position for el in b
	// itterate sorted list and find first value that is larger
	val_b = (*map)->stack_b->lst->value;
	temp_i = ft_dlstiter_v_4((*map)->stack_a->lst, val_b);
	printf("to push: %d\t... i: %ld\t\n", val_b, temp_i);
	// calculate the cost of pushing val b to correct position
	printf("max a: %d\tmin a: %d\n", (*map)->stack_a->max, (*map)->stack_a->min);
	if (val_b > (*map)->stack_a->max)
	{
		ft_pa(map);
		ft_ra(map);
		write(1, "pa\nra\n", 6);
	}
	else if (val_b < (*map)->stack_a->min)
	{
		ft_pa(map);
		write(1, "pa\n", 3);
	}
	else
	{
		res = ft_calc_act((*map)->stack_a, (*map)->stack_b, (int)temp_i, 0);
		printf("Configuration no %d\n", res);
		ft_calc_pun(map, &pun, (int)temp_i, 0);
		ft_do_act(map, &pun, res);
		ft_pa(map);
		ft_redo_act(map, &pun, res);
	}
}

void ft_sort_big(t_map **map)
{

}

void ft_sort(t_map **map)
{
	ft_init_stack_b(map);
	if ((*map)->size == 3)
		ft_sort_3(map);
	else if ((*map)->size == 4)
		ft_sort_4(map);
	else if ((*map)->size == 5)
		ft_sort_5(map);
	else
		ft_sort_big(map);
	printf("Sorting\n");
	ft_dlstiter((*map)->stack_a->lst, &ft_print_lst);
}

