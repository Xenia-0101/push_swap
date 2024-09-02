/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/02 22:34:28 by xenia            ###   ########.fr       */
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
