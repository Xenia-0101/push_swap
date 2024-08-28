/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:46:13 by xvislock          #+#    #+#             */
/*   Updated: 2024/05/22 18:46:13 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*
Parameters
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on
	the list.

Return value
	None

External functs.
	None

Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_cont *))
{
	if (!f)
		return ;
	if (!lst || !lst->content)
		return ;
	if (lst->next)
		ft_lstiter(lst->next, f);
	f(lst->content);
}
/**
 * @brief	Iterates the list ’lst’ and applies the function
			’f’ on the content of the node with index i.
 *
 * @param lst	lst to iterate
 * @param i		index to compare against
 * @param f		the address of the function to be applied
 */
void	ft_lstiter_i(t_list *lst, int i, void (*f)(t_cont *))
{
	if (!f)
		return ;
	if (!lst || !lst->content)
		return ;
	if (lst->next)
		ft_lstiter_i(lst->next, i, f);
	if (lst->content->index == i)
		f(lst->content);
}
