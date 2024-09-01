/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:27:24 by xenia             #+#    #+#             */
/*   Updated: 2024/09/01 13:10:58 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_act(int i, int j)
{
	printf("act: %d\t%d\n", i, j);
}

static void print_lst(t_dlist *lst)
{
	printf("lst: %ld\t%d\n", lst->index, lst->value);
	ft_actiter(lst->acts, &print_act);
}




void ft_test_act(void)
{
	t_dlist *lst;
	lst = ft_dlstnew(8);
	ft_dlstadd_front(&lst, ft_dlstnew(15));
	ft_dlstadd_front(&lst, ft_dlstnew(16));
	ft_dlstadd_front(&lst, ft_dlstnew(17));
	ft_dlstadd_back(&lst, ft_dlstnew(123));
	ft_dlstadd_back(&lst, ft_dlstnew(234));
	ft_dlstadd_back(&lst, ft_dlstnew(345));


	t_act *act_1;
	t_act *act_2;
	t_act *act_3;
	t_act *act_4;
	t_act *act_5;

	act_1 = ft_actnew(5, 1);
	act_2 = ft_actnew(13, 2);
	// ft_actadd_front(&act_1, act_2);
	// ft_actadd_front(&act_1, ft_actnew(33, 99));
	// act_3 = ft_actnew(58, 3);
	// ft_actadd_back(&act_1, act_3);
	// act_4 = ft_actnew(58, 4);
	// ft_actadd_back(&act_1, act_4);
	// ft_actiter(act_1, &print_act);
	printf("\n");
	ft_dlstiter(lst, &print_lst);
	t_act *new;
	new = ft_actnew(5, 8);

	lst->acts = new;
	if (!lst->acts)
	{
		printf("Something is wrong\n");
		return ;
	}
	else
	{
		printf("Something is good\n");
	}
	ft_actadd_back(&(lst->acts), act_1);
	ft_actadd_back(&(lst->acts), act_2);
	printf("list acts: %ld\t%d\n", lst->acts->cost, lst->acts->type);

	printf("\n");
	ft_dlstiter(lst, &print_lst);

	ft_dlstclear(&lst);





}
