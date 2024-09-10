/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/10 12:58:02 by xvislock         ###   ########.fr       */
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
void ft_print_acts(t_dlist *lst)
{
	printf("cost: %d\tconf:%d\npun: ", lst->cost, lst->conf);
	printf("%d %d %d %d\n", lst->pun[0], lst->pun[1], lst->pun[2], lst->pun[3]);
	printf("\n");
}
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
