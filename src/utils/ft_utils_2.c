/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 16:49:01 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isspace(int c)
{
	return ((c == '\f') | (c == '\n') | (c == '\r')
		| (c == '\t') | (c == '\v') | (c == ' '));
}

int	ft_just_space(char *str)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			res = 0;
		i++;
	}
	return (res);
}
