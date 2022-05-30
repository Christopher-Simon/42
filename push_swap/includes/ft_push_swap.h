/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:27:27 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 18:30:39 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "ft_my_lib.h"

typedef struct s_ppdpg
{
	int	index;
	int	value;
}	t_ppdpg;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_move;

typedef struct s_combi
{
	int	index_ppdpg;
	int	index_b;
	int	count;
}	t_combi;

typedef struct s_stack
{
	int				value;
	int				begin;
	int				min;
	struct s_stack	*next;
}	t_stack;

typedef struct s_full_stack
{
	struct s_stack	*a;
	struct s_stack	*b;
}	t_full_stack;

t_full_stack	*init_lst(int argc, char **argv);
void			ft_begin(t_full_stack *stack, int d);
void			ft_stack_new(t_full_stack *stack, int d);
void			print_stack(t_full_stack *stack);
void			free_stack(t_full_stack *stack);

void			swap_a(t_full_stack *stack, int silent);
void			swap_b(t_full_stack *stack, int silent);
void			push_a(t_full_stack *stack, int silent);
void			push_b(t_full_stack *stack, int silent);
void			rotate_a(t_full_stack *stack, int silent);
void			rotate_b(t_full_stack *stack, int silent);
void			reverse_rotate_a(t_full_stack *stack, int silent);
void			reverse_rotate_b(t_full_stack *stack, int silent);
void			rr(t_full_stack *stack, int silent);
void			rrr(t_full_stack *stack, int silent);

t_stack			*remove_root(t_stack *lst);
t_stack			*add_root(t_stack *lst, t_stack *root);
long int		ft_atol(const char *nptr, t_full_stack *stack);
int				stack_length(t_stack *lst);
int				check_order(t_full_stack *stack);
int				median(t_full_stack *stack);
void			get_median(t_full_stack *stack);
void			algo(t_full_stack *stack);
void			low_algo(t_full_stack *stack);
void			sort_3(t_full_stack *stack);
void			get_min(int *a, int *b);
int				get_max(t_stack *stack);

void			execut_order_66(t_full_stack *stack, t_move move);
int				count_value(t_move move);
int				for_b_find_direct_above(int b, t_full_stack *stack);
t_combi			selection(t_full_stack *stack, int index_b, int count);
t_ppdpg			send_min(t_full_stack *stack);
void			get_to_end(t_full_stack *stack);
int				verif(char **argv);
int				check_double(t_full_stack *stack);

#endif