/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:44:43 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/22 14:15:04 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int main(int argc, char **argv)
{
	char *nums_in;
	char **nums_sp;
	t_list *lst;
	// check arguments
	// no arg -> ask for numbers
	// one arg -> split list
	if (argc == 1)
	{
		nums_in = get_next_line(0);
		nums_sp = ft_split(nums_in, ' ');
	}
	else if (argc == 2)
	{
		nums_sp = ft_split(argv[1], ' ');
	}
	// a function which will create a linked list with one element

	// a function which will append to the linked list another element
	lst = ft_lstnew(ft_atoi(nums_sp[0]));
	return (0);
}