/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 07:29:41 by xenia             #+#    #+#             */
/*   Updated: 2024/10/06 07:34:05 by xenia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

// Double linked list structure
typedef struct s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	int				value;
}	t_dlist;

// Stack structure
typedef struct s_stack
{
	t_dlist	*lst;
	int		size;
}	t_stack;

// Map structure
typedef struct s_map
{
	t_stack	*stck;
	int		fd;
	int		state;
}	t_map;



#endif
