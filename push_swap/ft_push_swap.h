/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:27:27 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/27 15:58:42 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"

# define TRUE 1

typedef struct s_ppdpg
{
	int	index;
	int	value;
}	t_ppdpg;

typedef struct s_combi
{
	int	index_ppdpg;
	int index_b;
	int count;
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
	struct s_stack *a;
	struct s_stack *b;
}	t_full_stack;

void	ft_begin(t_full_stack *stack, int d);
void	ft_stack_new(t_full_stack *stack, int d);
void	print_stack(t_full_stack *stack);
void	free_stack(t_full_stack *stack);
void	swap_a(t_full_stack *stack);
void	swap_b(t_full_stack *stack);
void	push_a(t_full_stack *stack);
void	push_b(t_full_stack *stack);
void	rotate_a(t_full_stack *stack);
void	rotate_b(t_full_stack *stack);
void	reverse_rotate_a(t_full_stack *stack);
void	reverse_rotate_b(t_full_stack *stack);
void	rr(t_full_stack *stack);
void	rrr(t_full_stack *stack);
void	s_swap_a(t_full_stack *stack);
void	s_swap_b(t_full_stack *stack);
void	s_push_a(t_full_stack *stack);
void	s_push_b(t_full_stack *stack);
void	s_rotate_a(t_full_stack *stack);
void	s_rotate_b(t_full_stack *stack);
void	s_reverse_rotate_a(t_full_stack *stack);
void	s_reverse_rotate_b(t_full_stack *stack);
t_stack	*remove_root(t_stack *lst);
t_stack	*add_root(t_stack *lst, t_stack *root);
int     ft_atoi(const char *nptr);
int		stack_length(t_stack *lst);
int		check_order(t_full_stack *stack);
int		median(t_full_stack *stack);
void	get_median(t_full_stack *stack);
void	algo(t_full_stack *stack);
void	low_algo(t_full_stack *stack);
void	sort_3(t_full_stack *stack);
void	get_min(int *a, int *b);
int		get_max(t_stack *stack);
void	execut_order_66(t_full_stack *stack, int ra, int rb, int rra, int rrb);
int		for_b_find_direct_above(int b, t_full_stack *stack);
t_combi	selection(t_full_stack *stack);
t_ppdpg	send_min(t_full_stack *stack);
void	get_to_end(t_full_stack *stack);
int		verif(char **argv);

#endif