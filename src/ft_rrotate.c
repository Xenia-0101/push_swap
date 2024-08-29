/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:12:24 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/29 14:28:29 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/**
 * @brief 	Rotates the list variable lst is pointing to, s
 * 			o that the last node becomes the first node.
 * 	Get reach of the last node ("tmp") and set the second-to-last.next to null.
 * 	Create a new node "last" which will have the same value as the last node.
 * 	Add the "last" node to the front of the list.
 * 	** No need to reset indices - taken care for in the ft_lst_addfront **
 *
 * @param lst A pointer to the pointer of the list to be rotated.
 */
void ft_rrotate(t_list **lst)
{
	t_list *last;
	t_list *tmp;

	if (!*lst)
		return ;
	if (!(*lst)->content || !(*lst)->next)
		return ;
	tmp = ft_lstlast(*lst);
	tmp->prev->next = NULL;
	last = ft_lstnew(tmp->content->value);
	ft_lstdelone(tmp, &ft_del_cont);
	ft_lstadd_front(lst, last);
}
