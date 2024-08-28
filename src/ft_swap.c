/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:02:30 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/28 19:05:36 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements. */

void ft_swap(t_list *lst)
{
	int temp;

	if (!lst->content || !lst->next->content)
		return ;
	temp = lst->content->value;
	lst->content->value = lst->next->content->value;
	lst->next->content->value = temp;
}