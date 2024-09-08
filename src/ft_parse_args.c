/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:40 by xenia             #+#    #+#             */
/*   Updated: 2024/09/08 16:55:24 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_init_limits(t_stack **stack, int v)
{
	(*stack)->min = v;
	(*stack)->max = v;
}

static void	ft_parse_long(t_stack **st, char *arg)
{
	t_dlist	*new;
	int		i;

	if (!arg || !*arg)
	{
		write(2, "Error\n", 6);
		ft_free_stack(st);
		exit(1);
	}
	(*st)->ph = ft_split(arg, ' ');
	(*st)->size = ft_get_num_count((*st)->ph);
	ft_init_limits(st, ft_atoi((*st)->ph[0]));
	i = 0;
	while (i < (*st)->size)
	{
		new = ft_dlstnew(ft_atoi_check(st, (*st)->ph[i]));
		if (new->value > (*st)->max)
			(*st)->max = new->value;
		if (new->value < (*st)->min)
			(*st)->min = new->value;
		ft_dlstadd_back(&(*st)->lst, new);
		i++;
	}
}

static void	ft_parse_many(t_stack **stack, int argc, char **argv)
{
	t_dlist	*new;
	int		i;

	(*stack)->size = argc - 1;
	ft_init_limits(stack, ft_atoi(argv[1]));
	i = 1;
	while (i < argc)
	{
		new = ft_dlstnew(ft_atoi_check(stack, argv[i]));
		if (new->value > (*stack)->max)
			(*stack)->max = new->value;
		if (new->value < (*stack)->min)
			(*stack)->min = new->value;
		ft_dlstadd_back(&(*stack)->lst, new);
		i++;
	}
}

void	ft_parse_args(t_stack **stack, int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		ft_free_stack(stack);
		exit(1) ;
	}
		if (argc == 2)
	{
		ft_parse_long(stack, argv[1]);
	}
	else
	{
		ft_parse_many(stack, argc, argv);
	}
	(*stack)->cheap = (*stack)->size;
}

