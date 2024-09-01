/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:40 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 15:43:08 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_parse_long(t_stack **st, char *arg)
{
	t_dlist	*new;
	int		i;

	(*st)->ph = ft_split(arg, ' ');
	(*st)->size = ft_get_num_count((*st)->ph);
	i = 0;
	while (i < (*st)->size)
	{
		new = ft_dlstnew(ft_atoi_check(st, (*st)->ph[i]));
		ft_dlstadd_back(&(*st)->lst, new);
		i++;
	}
}

static void	ft_parse_many(t_stack **stack, int argc, char **argv)
{
	t_dlist	*temp;
	int		i;

	(*stack)->size = argc - 1;
	i = 1;
	while (i < argc)
	{
		temp = ft_dlstnew(ft_atoi_check(stack, argv[i]));
		ft_dlstadd_back(&(*stack)->lst, temp);
		i++;
	}
}

void	ft_parse_args(t_stack **stack, int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "ERROR: No argument provided.\n", 29);
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
	printf("Stack values: %d, %ld, %d\n", (*stack)->max, (*stack)->size, (*stack)->lst->value);
}

