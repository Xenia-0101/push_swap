/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:15:36 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/29 15:53:38 by xvislock         ###   ########.fr       */
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
	// printf("***%d***\n", cont->value);
	printf("%d\t%d\n", cont->index, cont->value);
}

static void ft_free_split(char **str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int main(void)
{
	// assume input in the form of a string
	char *in = "5 6 8 1 0 15 22 101 4";
	char **in_2 = ft_split(in, ' ');
	int count = ft_get_num_count(in_2);

	// create struct
	t_list *stack_a;
	t_list *stack_b;
	t_list *tmp;

	stack_a = NULL;
	stack_b = NULL;
	int i = 0;
	while (i < count)
	{
		tmp = ft_lstnew(ft_atoi(in_2[i]));
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}

	ft_lstclear(&stack_a, &ft_del_cont);
	ft_lstclear(&stack_b, &ft_del_cont);
	ft_free_split(in_2, count);
	return (0);
}

/* int main(void)
{
	char *in = "5 6 8 1 0 15 22 101 4";
	char **in_2 = ft_split(in, ' ');

	// create struct
	t_list *lst;
	t_list *tmp;

	// first node -> index 0 value 5, next null, prev null
	lst = ft_lstnew(ft_atoi(in_2[0]));
	printf("%d\t%d\t%d\t%d\n\n", lst->content->index, lst->content->value, (lst->next != NULL), (lst->prev != NULL));

	// add nodes to the front
	tmp = ft_lstnew(ft_atoi(in_2[1]));
	ft_lstadd_front(&lst, tmp);
	tmp = ft_lstnew(ft_atoi(in_2[2]));
	ft_lstadd_front(&lst, tmp);
	// lst should have 3 nodes: 8, 6, 5
	printf("%d\t%d\t%d\t%d\n", lst->content->index, lst->content->value, (lst->next != NULL), (lst->prev != NULL));
	printf("%d\t%d\t%d\t%d\n", lst->next->content->index, lst->next->content->value, (lst->next->next != NULL), (lst->next->prev != NULL));
	printf("%d\t%d\t%d\t%d\n\n", lst->next->next->content->index, lst->next->next->content->value, (lst->next->next->next != NULL), (lst->next->next->prev != NULL));

	// add nodes to the back
	tmp = ft_lstnew(ft_atoi(in_2[3]));
	ft_lstadd_back(&lst, tmp);
	tmp = ft_lstnew(ft_atoi(in_2[4]));
	ft_lstadd_back(&lst, tmp);
	// lst should have 5 nodes: 8, 6, 5, 1, 0
	printf("%d\t%d\t%d\t%d\n", lst->content->index, lst->content->value, (lst->next != NULL), (lst->prev != NULL));
	printf("%d\t%d\t%d\t%d\n", lst->next->content->index, lst->next->content->value, (lst->next->next != NULL), (lst->next->prev != NULL));
	printf("%d\t%d\t%d\t%d\n", lst->next->next->content->index, lst->next->next->content->value, (lst->next->next->next != NULL), (lst->next->next->prev != NULL));
	printf("%d\t%d\t%d\t%d\n", lst->next->next->next->content->index, lst->next->next->next->content->value, (lst->next->next->next->next != NULL), (lst->next->next->next->prev != NULL));
	printf("%d\t%d\t%d\t%d\n\n", lst->next->next->next->next->content->index, lst->next->next->next->next->content->value, (lst->next->next->next->next->next != NULL), (lst->next->next->next->next->prev != NULL));

}
 */
