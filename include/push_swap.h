/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenia <xenia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:16:23 by xvislock          #+#    #+#             */
/*   Updated: 2024/09/22 17:21:06 by xenia            ###   ########.fr       */
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
	int		cost;		// count of total movements to get two nodes on top
	int		conf;		// the conf to get two nodes on top (vals 1 - 4)
	int		pun[4];		// the steps to be taken to get nodes on top
}	t_act;

// Double linked list structure
typedef struct s_dlist
{
	struct s_dlist	*prev;
	struct s_dlist	*next;
	int				ipo;		// idx above which a node should be pushed
	int				cost;
	int				conf;
	int				pun[4];
	int				index;
	int				value;
}	t_dlist;

// Stack structure
typedef struct s_stack
{
	t_dlist	*lst;
	int		size;
	int		cheap;
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
	int		size;
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
void	ft_dlstiter_v_last(t_dlist *lst, int v, int *i);
int		ft_dlstiter_v_first(t_dlist *lst, int v);
void	ft_dlstiter_max(t_dlist *lst, int v, int *tv);
void	ft_dlstiter_min(t_dlist *lst, int v, int *tv);
void	ft_dlstiter_high_low(t_dlist *lst, int v, int *tv, int *ti);
void	ft_dlstiter_low_high(t_dlist *lst, int v, int *tv, int *ti);
void	ft_dlstiter_cheap(t_dlist *lst, int *c, int pun[4]);

t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstat_i(t_dlist *lst, int i);
void	ft_dlstdelone(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);

/* utils */
int		ft_atoi_check(t_stack **stack, const char *nptr);
void	ft_decr_idx(t_dlist *lst);
void	ft_incr_index(t_dlist *lst);
void	ft_check_limits(t_stack **s1, t_stack **s2);
void	ft_write_rr(int ra_c, int rb_c, int rr_c);
void	ft_write_rrr(int ra_c, int rb_c, int rr_c);

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
void	ft_sort_5_rev(t_map **map);

/* ft_sort_big_1 */
void	ft_sort_big_1(t_map **map, t_stack *stack_a);

/* ft_sort_big_2 */
void	ft_sort_big_2(t_map **map, t_stack *stack_b);

/* pun */
int		ft_calc_conf(t_map **map, t_dlist **lst, int ia, int ib);
void	ft_calc_pun(t_map **map, t_dlist **lst, int ia, int ib);
void	ft_pun_rotate(t_map **map, int pun[4]);

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
void	ft_pun_rotate(t_map **map, int pun[4]);

/* utils.c */
void	ft_del_cont(t_cont *cont);
int		ft_get_num_count(char **in);
int		ft_max(int a, int b);
int		ft_min_tab(int *tab, int s);
int		ft_isspace(int c);
int		ft_just_space(char *str);

#endif
