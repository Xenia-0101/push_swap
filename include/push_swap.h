/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xvislock <xvislock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:16:23 by xvislock          #+#    #+#             */
/*   Updated: 2024/08/29 15:15:06 by xvislock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

# include "../libft/include/libft.h"

/* *** Prototypes *** */

/* list manipulations */
void ft_swap(t_list *lst);
void ft_push(t_list **lst1, t_list **lst2);
void ft_rotate(t_list **lst);
void ft_rrotate(t_list **lst);

/* utils.c */
void ft_del_cont(t_cont *cont);

#endif