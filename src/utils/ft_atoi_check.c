/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:44:20 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/22 18:44:20 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c);


/**
 * if there are chars after number is parsed, atoi exits program.
 */
int	ft_atoi_check(t_stack **stack, const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	if (!nptr || !*nptr)
	{
		write(2, "\033[0;31mERROR: empty argument.\033[0m\n", 34);
		ft_free_stack(stack);
		exit(1);
	}
	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	if (nptr[i])
	{
		write(2, "\033[0;31mERROR: Invalid format of arguments.\033[0m\n", 47);
		ft_free_stack(stack);
		exit(1);
	}
	return (res * sign);
}

static int	ft_isspace(int c)
{
	return ((c == '\f') | (c == '\n') | (c == '\r')
		| (c == '\t') | (c == '\v') | (c == ' '));
}
