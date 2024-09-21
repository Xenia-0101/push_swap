/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 12:00:52 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_isspace(int c)
{
	return ((c == '\f') | (c == '\n') | (c == '\r')
		| (c == '\t') | (c == '\v') | (c == ' '));
}

int ft_just_space(char *str)
{
	int i;
	int res;

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

void ft_del_cont(t_cont *cont)
{
	cont->value = 0;
	cont->index = 0;
	free(cont);
}

size_t	ft_get_num_count(char **in)
{
	size_t	count = 0;

	while (in[count])
	{
		count++;
	}
	return (count);
}

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_min_tab(int *tab, int s)
{
	int i;
	int ti;
	int v;

	i = 0;
	ti = i;
	v = tab[0];
	while (i < s)
	{
		if (tab[i] < v)
		{
			v = tab[i];
			ti = i;
		}
		i++;
	}
	return (ti);
}
