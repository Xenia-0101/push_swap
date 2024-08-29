/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:42 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/22 18:45:42 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Parameters
		lst: The address of a pointer to the first link of
		a list.
		new: The address of a pointer to the node to be
		added to the list.

	Return value
		None

	External functs.
		None

	Description
		Increases index of each node in lst by 1.
		Adds the node ’new’ at the beginning of the list.
*/


#include "../include/libft.h"

static void ft_incr_index(t_cont *node)
{
	if (!node)
		return ;
	node->index++;
}

static void ft_decr_index(t_cont *node)
{
	if (!node)
		return ;
	node->index--;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->content->index > 0)
	{
		ft_lstiter(*lst, &ft_decr_index);
	}
	ft_lstiter(*lst, &ft_incr_index);
	(*lst)->prev = new;
	new->next = *lst;
	*lst = new;
}
