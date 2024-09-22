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

static void	ft_exit_ps(t_stack **stack);
static int	ft_set_sign(char c, int *sign);
int			ft_atoi_check(t_stack **stack, const char *nptr);

static void	ft_exit_ps(t_stack **stack)
{
	write(2, "Error\n", 6);
	ft_free_stack(stack);
	exit(1);
}

static int	ft_set_sign(char c, int *sign)
{
	if (c && (c == '+' || c == '-'))
	{
		if (c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

/**
 * if there are chars after number is parsed, atoi exits program.
 */
int	ft_atoi_check(t_stack **stack, const char *nptr)
{
	long	res;
	int		sign;
	int		i;

	if (!nptr || !*nptr)
		ft_exit_ps(stack);
	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	i += ft_set_sign(nptr[i], &sign);
	if (!nptr[i] || !ft_isdigit(nptr[i]))
		ft_exit_ps(stack);
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = 10 * res + (nptr[i] - '0');
		i++;
	}
	if (nptr[i])
		ft_exit_ps(stack);
	if (res * sign > 2147483647 || res * sign < -2147483648)
		ft_exit_ps(stack);
	return ((int)(res * sign));
}
