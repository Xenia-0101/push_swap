/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:57:00 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 10:36:33 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
typedef struct s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	t_act			*acts;
	size_t			index;
	int				value;
}	t_dlist;
*/

t_dlist	*ft_dlstnew(int val)
{
	t_dlist	*lst;

	lst = (t_dlist *)ft_calloc(1, sizeof (t_dlist));
	if (!lst)
		return (NULL);
	lst->prev = NULL;
	lst->next = NULL;
	lst->acts = NULL;
	lst->index = 0;
	lst->value = val;
	return (lst);
}
