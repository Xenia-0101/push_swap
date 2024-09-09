/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:45:40 by xenia             #+#    #+#             */
/*   Updated: 2024/09/09 17:30:37 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_parse_many(t_stack **stack, int argc, char **argv);
static void	ft_parse_long(t_stack **st, char *arg);
static void	ft_init_limits(t_stack **stack, int v);
void		ft_parse_args(t_stack **stack, int argc, char **argv);

static void	ft_init_limits(t_stack **stack, int v)
{
	(*stack)->min = v;
	(*stack)->max = v;
}
/**
 * @brief Convert an argument into a list of arguments and create a stack
 * 			Check if the arg is valid
 * 			Split arg and save it in stack.ph
 * 			Set stack.size to the stack.ph element count
 * 			Set stack limits to the first value in stack.ph
 * 			Iterate stack.ph:
 * 				Convert element to int
 * 				Create a new dlst node
 * 				Check node value against stack limits
 * 				Add the node to the back of stacl.lst
 *
 * @param st	Pointer to stack a
 * @param arg	A string of space separated values
 */
static void	ft_parse_long(t_stack **st, char *arg)
{
	t_dlist	*new;
	int		i;

	if (!arg || !*arg || ft_just_space(arg))
	{
		write(2, "Error\n", 6);
		ft_free_stack(st);
		exit(1);
	}
	(*st)->ph = ft_split(arg, ' ');
	(*st)->size = ft_get_num_count((*st)->ph);
	ft_init_limits(st, ft_atoi((*st)->ph[0]));
	i = 0;
	while (i < (*st)->size)
	{
		new = ft_dlstnew(ft_atoi_check(st, (*st)->ph[i]));
		if (new->value > (*st)->max)
			(*st)->max = new->value;
		if (new->value < (*st)->min)
			(*st)->min = new->value;
		ft_dlstadd_back(&(*st)->lst, new);
		i++;
	}
}
/**
 * @brief Convert a list of arguments into a stack
 * 			Set stack.size to the argument count
 * 			Set stack.min and stack.max to the first value
 * 			Iterate arguments and:
 * 				Convert argument to int
 * 				Create a new dlst node
 * 				Check the new value against stack limits
 * 				Add the new node to the back of stack.lst
 *
 * @param stack	Pointer to stack a
 * @param argc	Argument count
 * @param argv	Arguments
 */
static void	ft_parse_many(t_stack **stack, int argc, char **argv)
{
	t_dlist	*new;
	int		i;

	(*stack)->size = argc - 1;
	ft_init_limits(stack, ft_atoi(argv[1]));
	i = 1;
	while (i < argc)
	{
		new = ft_dlstnew(ft_atoi_check(stack, argv[i]));
		if (new->value > (*stack)->max)
			(*stack)->max = new->value;
		if (new->value < (*stack)->min)
			(*stack)->min = new->value;
		ft_dlstadd_back(&(*stack)->lst, new);
		i++;
	}
}
/**
 * @brief	Check number of arguments passed and call appropriate action
 * 			If argc is 1 - free and exit
 * 			If argc is 2 - parse long argument
 * 			Else - parse many arguments
 *
 * @param stack Pointer to stack a
 * @param argc	Argument count
 * @param argv	Arguments
 */
void	ft_parse_args(t_stack **stack, int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		ft_free_stack(stack);
		exit(1) ;
	}
		if (argc == 2)
	{
		ft_parse_long(stack, argv[1]);
	}
	else
	{
		ft_parse_many(stack, argc, argv);
	}
	(*stack)->cheap = (*stack)->size;
}

