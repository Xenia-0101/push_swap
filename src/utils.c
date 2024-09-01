/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/01 14:50:48 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
