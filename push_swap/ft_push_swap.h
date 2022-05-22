/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:27:27 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/22 08:46:45 by chsimon          ###   ########.fr       */
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

t_stack	*ft_begin(int d);
void	ft_stack_new(t_stack *ptr, int d);
void	print_stack(t_stack *a, t_stack *b);
t_stack	*swap_a(t_stack *a);
t_stack	*push_b(t_stack **a, t_stack *b);

#endif