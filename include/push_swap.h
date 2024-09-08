/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:16:23 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/08 10:28:14 by xenia            ###   ########.fr       */
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

/* *** Sturctures *** */

// Pun square
/**
 *				   ra    rra     rb    rrb
 *				|------+------+------+------|
 *		r[0] : 	|  ia  |   0  |  ib  |   0  |
 *				|------+------+------+------|
 *		r[1] : 	|  ia  |   0  |   0  | s-ib |
 *				|------+------+------+------|
 *		r[2] : 	|   0  | s-ia |  ib  |   0  |
 *				|------+------+------+------|
 *		r[3] : 	|   0  | s-ia |   0  | s-ib |
 *				|------+------+------+------|
 */

// Action list structure
typedef struct s_act
{
	int		ipo;		// idx of elem above which num should be pushed
	int		cost;		// count of total movements to get desired elements on top
	int		conf;		// the configuration to get the elements on top (vals 1 - 4)
	int		pun[4];		// the steps to be taken to get elements on top
}	t_act;

// Double linked list structure
typedef struct s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	int				ipo;		// idx of elem above which num should be pushed
	int				cost;		// count of total movements to get desired elements on top
	int				conf;		// the configuration to get the elements on top (vals 1 - 4)
	int				pun[4];		// the steps to be taken to get elements on top
	size_t			index;
	int				value;
}	t_dlist;

// Stack structure
typedef struct s_stack
{
	t_dlist	*lst;
	size_t	size;
	size_t	cheap;
	char	**ph;	// placeholder
	int		min;
	int		max;
}	t_stack;

// Map structure
typedef struct s_map
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_act	*acts;
	size_t	size;
	int		min;
	int		max;
	int		state; // to keep hold of sorted state
}	t_map;

/* *** Prototypes *** */

/* TO DELETE */
void ft_test_act(void);
/* lists - basic functions */
t_act	*ft_actnew(size_t cost, int type);
void	ft_actadd_back(t_act **act, t_act *new);
void	ft_actadd_front(t_act **act, t_act *new);
void	ft_actiter(t_act *act, void (*f)(int c, int t));
t_act	*ft_actlast(t_act *act);
size_t	ft_actsize(t_act *act);
void	ft_actdelone(t_act *act);
void	ft_actclear(t_act **act);

t_dlist	*ft_dlstnew(int val);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *));
void	ft_dlstiter_i(t_dlist *lst, size_t i, void (*f)(t_dlist *));
size_t	ft_dlstiter_v(t_dlist *lst, int v);
size_t	ft_dlstiter_v_2(t_dlist *lst, int v, int *tv);
size_t	ft_dlstiter_v_2_max(t_dlist *lst, int v, int *tv);
void	ft_dlstiter_2_max(t_dlist *lst, int v, int *tv);
size_t	ft_dlstiter_v_3(t_dlist *lst, int v, int *tv);
void	ft_dlstiter_high_low(t_dlist *lst, int v, int *tv, int *ti);
void	ft_dlstiter_low_high(t_dlist *lst, int v, int *tv, int *ti);
void	ft_dlstiter_3_min(t_dlist *lst, int v, int *tv);
size_t	ft_dlstiter_v_4(t_dlist *lst, int v);
t_dlist	*ft_dlstlast(t_dlist *lst);
size_t	ft_dlstsize(t_dlist *lst);
void	ft_dlstdelone(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);

/* utils */
int		ft_atoi_check(t_stack **stack, const char *nptr);

/* ft_free */
void	ft_free_split(char **str, int len);
void	ft_free_stack(t_stack **stack);
void	ft_free_map(t_map **map);
/* ft_init */
void	ft_init_stack_a(t_stack **stack);
void	ft_init_map(t_map **map, t_stack *stack_a);
void	ft_init_stack_b(t_map **map);
/* ft_parse_args */
void	ft_parse_args(t_stack **stack, int argc, char **argv);

/* ft_is_unique */
int		ft_is_unique(t_stack **stack);

/* ft_is_sorted */
int		ft_is_sorted(t_map *map);

/* ft_sort_reverse */
void	ft_sort_reverse(t_map **map);

/* ft_sort */
void	ft_sort(t_map **map);
void	ft_sort_3(t_map **map);

/* pun */
int ft_calc_act_big(t_map **map, t_dlist **lst, int ia, int ib);
void ft_calc_pun_big(t_map **map, t_dlist **lst, int ia, int ib);
void ft_print_pun(int i[4]);
void ft_do_act_big(t_map **map, int pun[4]);
// void ft_calc_pun(t_map **map, t_pun *pun, int ia, int ib);
// int ft_calc_act(t_stack *st_a, t_stack *st_b, int ia, int ib);
// void ft_do_act(t_map **map, t_pun *pun, int r);
// void ft_redo_act(t_map **map, t_pun *pun, int r);


/* actions */
void	ft_pa(t_map **map);
void	ft_pb(t_map **map);
void	ft_ra(t_map **map);
void	ft_rb(t_map **map);
void	ft_ra_x(t_map **map, int i);
void	ft_rb_x(t_map **map, int i);
void	ft_rra(t_map **map);
void	ft_rrb(t_map **map);
void	ft_rra_x(t_map **map, int i);
void	ft_rrb_x(t_map **map, int i);
void	ft_sa(t_map **map);
void	ft_sb(t_map **map);

/* utils.c */
void	ft_del_cont(t_cont *cont);
size_t	ft_get_num_count(char **in);
void ft_print_lst(t_dlist *lst);
int ft_max(int a, int b);
int ft_min_tab(int *tab, int s);

#endif
