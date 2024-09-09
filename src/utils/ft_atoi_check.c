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

/**
 * if there are chars after number is parsed, atoi exits program.
 */
int	ft_atoi_check(t_stack **stack, const char *nptr)
{
	// printf("%d %d %d\n", -2147483648, 2147483648, 2147483647 );
	int	res;
	int	sign;
	int	i;
	if (!nptr || !*nptr)
	{
		write(2, "Error\n", 6);
		ft_free_stack(stack);
		exit(1);
	}
	if (!ft_strncmp(nptr, "-2147483648", 11))
	{
		return (-2147483648);
	}

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
	{
		i++;
	}
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!nptr[i] || !ft_isdigit(nptr[i]))
	{
		write(2, "Error\n", 6);
		ft_free_stack(stack);
		exit(1);
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	if (nptr[i])
	{
		write(2, "Error\n", 6);
		ft_free_stack(stack);
		exit(1);
	}
	return (res * sign);
}
