/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/07 20:55:03 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ft_print_lst(t_dlist *lst)
{
	// printf("***%d***\n", cont->value);
	printf("%ld\t%d\n", lst->index, lst->value);
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
