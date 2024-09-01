/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:15:36 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/01 15:47:19 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void ft_print_lst(t_dlist *lst)
{
	// printf("***%d***\n", cont->value);
	printf("%ld\t%d\n", lst->index, lst->value);
}


int main(int argc, char **argv)
{
	t_stack *stack_a;
	ft_init_stack_a(&stack_a);

	// parse args - check the argc and build stack A
	ft_parse_args(&stack_a, argc, argv);
	ft_dlstiter(stack_a->lst, &ft_print_lst);

	ft_free_stack(&stack_a);


	return (0);
}

