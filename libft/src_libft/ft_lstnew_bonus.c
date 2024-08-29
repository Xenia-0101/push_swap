/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:46:37 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/22 18:46:37 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief	Allocates with calloc and returns a new node.
 * 			Allocates with calloc a new content.
 * 			The content.value is initialized with val,
 * 			the content.index is initialized to 0.
 * 			The *prev and *next pointers are initialized to NULL.
 * @param val	The value of content.value.
 * @return	The new node.
 */
t_list	*ft_lstnew(int val)
{
	t_list	*list;
	t_cont	*cont;

	list = (t_list *)ft_calloc(1, sizeof (t_list));
	if (!list)
		return (NULL);
	cont = (t_cont *)ft_calloc(1, sizeof (t_cont));
	if (!cont)
		return (NULL);
	cont->value = val;
	cont->index = 0;
	list->content = cont;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}


