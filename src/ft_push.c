/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/29 15:41:17 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



/**
 * @brief Take the first element at the top of lst1 and put it at the top of lst2. Do nothing if lst1 is empty.
 *
 * @param lst1
 * @param lst2
 */
void ft_push(t_list **lst1, t_list **lst2)
{
	t_list *new;
	t_list *tmp;

	if (!*lst1 || !(*lst1)->content)
		return ;
	printf("ft_push\n");
	// create new node with val as first node in lst1
	new = ft_lstnew((*lst1)->content->value);
	// save pointer to the first node
	tmp = *lst1;
	// shift lst1 to the next node
	*lst1 = (*lst1)->next;
	(*lst1)->prev = NULL;
	// delete the first node
	ft_lstdelone(tmp, &ft_del_cont);
	// push new to lst2
	ft_lstadd_front(lst2, new);
}
