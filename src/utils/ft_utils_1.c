/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 16:52:28 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_del_cont(t_cont *cont)
{
	cont->value = 0;
	cont->index = 0;
	free(cont);
}

int	ft_get_num_count(char **in)
{
	int	count;

	count = 0;
	while (in[count])
	{
		count++;
	}
	return (count);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min_tab(int *tab, int s)
{
	int	i;
	int	ti;
	int	v;

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
