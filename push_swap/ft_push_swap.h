/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:27:27 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/22 19:40:14 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				begin;
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
void	swap_a(t_full_stack *stack);
void	swap_b(t_full_stack *stack);
void	push_a(t_full_stack *stack);
void	push_b(t_full_stack *stack);
void	rotate_a(t_full_stack *stack);
void	rotate_b(t_full_stack *stack);
void	reverse_rotate_a(t_full_stack *stack);
void	reverse_rotate_b(t_full_stack *stack);


#endif