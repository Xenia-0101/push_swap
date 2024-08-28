/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:45:57 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/22 18:45:57 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters
	lst: The node to free.
	del: The address of the function used to delete
	the content.

Return value
	None

External functs.
	free

Description
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.

** Modified version of ft_lstdelone
	make sure the del function frees the content
*/

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(t_cont *))
{
	if (!del)
		return ;
	if (!lst->content)
	{
		free(lst);
		return ;
	}
	del(lst->content);
	free(lst);
}
