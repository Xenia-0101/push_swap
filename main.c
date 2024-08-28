/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:15:36 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/28 19:08:54 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int ft_get_num_count(char **in)
{
	int count = 0;

	while (in[count])
	{
		count++;
	}
	return (count);
}

void ft_print_by_idx(t_cont *cont)
{
	printf("***%d***\n", cont->value);
}

int main(void)
{
	// assume input in the form of a string
	char *in = "5 6 8 1 0 15 22 101 4";
	char **in_2 = ft_split(in, ' ');
	int count = ft_get_num_count(in_2);

	// create struct
	t_list *lst;
	t_list *tmp;

	lst = ft_lstnew(55, 0);
	printf("%d\n", lst->content->value);
	int i = 0;
	while (i < count)
	{
		tmp = ft_lstnew(ft_atoi(in_2[i]), i + 1);
		printf("%d\t%d\n", tmp->content->index, tmp->content->value);
		ft_lstadd_back(&lst, tmp);
		i++;
	}
	ft_lstiter_i(lst, 0, &(ft_print_by_idx));
	ft_swap(lst);
	ft_lstiter_i(lst, 0, &(ft_print_by_idx));

	return (0);
}