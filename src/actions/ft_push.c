/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:29:53 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/02 23:34:22 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_decr_idx(t_dlist *lst)
{
	lst->index--;
}

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
/**
 * @brief
 * Take the first element at the top of a and put it at the top of b.
 * Do nothing if a is empty.
 * Decrease size of a, increase size of b.
 * Take care of indeces.
 *
	typedef struct s_dlist
	{
		struct s_dlist	*prev;
		struct s_dlist	*next;
		t_act			*acts;
		size_t			index;
		int				value;
	}	t_dlist;

 * @param map
 */
void ft_pb(t_map **map)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist	**lst_a;
	t_dlist **lst_b;

	lst_a = &(*map)->stack_a->lst;
	lst_b = &(*map)->stack_b->lst;
	if (!*lst_a || !(*lst_a)->value)
		return ;
	new = ft_dlstnew((*lst_a)->value);
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	if (*lst_a)
		(*lst_a)->prev = NULL;
	ft_dlstdelone(temp);
	ft_dlstadd_front(lst_b, new);
	(*map)->stack_a->size--;
	(*map)->stack_b->size++;
	ft_dlstiter((*lst_a), &ft_decr_idx);
}

void ft_pa(t_map **map)
{
	t_dlist *new;
	t_dlist *temp;
	t_dlist	**lst_a;
	t_dlist **lst_b;

	lst_a = &(*map)->stack_a->lst;
	lst_b = &(*map)->stack_b->lst;
	if (!*lst_b || !(*lst_b)->value)
		return ;
	new = ft_dlstnew((*lst_b)->value);
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	if (*lst_b)
		(*lst_b)->prev = NULL;
	ft_dlstdelone(temp);
	ft_dlstadd_front(lst_a, new);
	(*map)->stack_a->size++;
	(*map)->stack_b->size--;
	ft_dlstiter((*lst_b), &ft_decr_idx);
}
