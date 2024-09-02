/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:42:27 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/29 15:48:07 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief	Rotates the list variable lst is pointing to,
 * 			so that the fires element becomes the last one.
 *
 * 	Create a new node ("first") with cont.value the same as the lst first node cont.value.
 * 	Shift lst pointer to the next node and delete the first node.
 * 	Add "first" to the back of the lst.
 *
 * @param lst A pointer to the pointer of the list to be rotated.
 */
void ft_rotate(t_list **lst)
{
	t_list *first;
	t_list *tmp;

	if (!*lst)
		return ;
	if (!(*lst)->content || !(*lst)->next)
		return ;
	first = ft_lstnew((*lst)->content->value);
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	ft_lstdelone(tmp, &ft_del_cont);
	ft_lstadd_back(lst, first);
	return ;
}
