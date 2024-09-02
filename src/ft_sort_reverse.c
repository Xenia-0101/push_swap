/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:42:46 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/02 09:56:57 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_reverse(t_map **map)
{
	ft_init_stack_b(map);
	ft_pb(map);
	ft_pb(map);
	ft_free_map(map);
	exit (0);
}