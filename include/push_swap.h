/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:16:23 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/21 12:27:33 by xenia            ###   ########.fr       */
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
	size_t	cost;		// count of total movements to get desired elements on top
	int		conf;		// the configuration to get the elements on top (vals 1 - 4)
	int		pun[4];		// the steps to be taken to get elements on top
}	t_act;

// Double linked list structure
typedef struct s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	int				ipo;		// idx of elem above which num should be pushed
	size_t			cost;		// count of total movements to get desired elements on top
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
	int		ih[4];	// placeholder for pun
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

/* lists - basic functions */
t_dlist	*ft_dlstnew(int val);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *));
size_t	ft_dlstiter_v(t_dlist *lst, int v);								// ft_sort.c: ft_sort_3
void	ft_dlstiter_v_1(t_dlist *lst, int v, int *i);
void	ft_dlstiter_2_max(t_dlist *lst, int v, int *tv);				// ft_push.c: ft_check_limits
void	ft_dlstiter_high_low(t_dlist *lst, int v, int *tv, int *ti);	// ft_sort.c: ft_sort_big
void	ft_dlstiter_low_high(t_dlist *lst, int v, int *tv, int *ti);	// ft_sort.c: ft_sort_big
void	ft_dlstiter_3_min(t_dlist *lst, int v, int *tv);				// ft_push.c: ft_check_limits
size_t	ft_dlstiter_v_4(t_dlist *lst, int v);							// ft_sort.c: ft_sort_4
void	ft_dlstiter_cheap(t_dlist *lst, size_t *c, int pun[4]);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstat_i(t_dlist *lst, int i);
void	ft_dlstdelone(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);

/* utils */
int		ft_atoi_check(t_stack **stack, const char *nptr);
void	ft_decr_idx(t_dlist *lst);
void	ft_check_limits(t_stack **s1, t_stack **s2);

/* ft_free */
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

/* ft_sort_mini */
void	ft_sort_2(t_map **map);
void	ft_sort_3(t_map **map);
void	ft_sort_4(t_map **map);
// void	ft_sort_5(t_map **map);

/* pun */
int		ft_calc_act_big(t_map **map, t_dlist **lst, int ia, int ib);
void	ft_calc_pun_big(t_map **map, t_dlist **lst, int ia, int ib);
void	ft_do_act_big(t_map **map, int pun[4]);

/* actions */
void	ft_pa(t_map **map);
void	ft_pb(t_map **map);
void	ft_ra(t_map **map, int p);
void	ft_rb(t_map **map, int p);
void	ft_ra_x(t_map **map, int i, int p);
void	ft_rb_x(t_map **map, int i, int p);
void	ft_rra(t_map **map, int p);
void	ft_rrb(t_map **map, int p);
void	ft_rra_x(t_map **map, int i, int p);
void	ft_rrb_x(t_map **map, int i, int p);
void	ft_sa(t_map **map);
void	ft_sb(t_map **map);

/* utils.c */
void	ft_del_cont(t_cont *cont);
size_t	ft_get_num_count(char **in);
void	ft_print_lst(t_dlist *lst);
int		ft_max(int a, int b);
int		ft_min_tab(int *tab, int s);
int		ft_isspace(int c);
int		ft_just_space(char *str);
void	ft_print_acts(t_dlist *lst);

#endif
