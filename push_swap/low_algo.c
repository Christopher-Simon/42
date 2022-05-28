/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:52:37 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/26 16:10:52 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	insert_bt(t_full_stack *stack)
{
	s_push_b(stack);
	s_swap_a(stack);
	if (stack->a->next->value
		> stack->a->next->next->value
		&& stack_length(stack->a) > 2)
		insert_bt(stack);
	s_push_a(stack);
}

void	insert(t_full_stack *stack)
{
	s_push_a(stack);
	if (stack->a->value > stack->a->next->value)
		s_swap_a(stack);
	if (stack->a->next->value
		> stack->a->next->next->value)
		insert_bt(stack);
}

void	low_algo(t_full_stack *stack)
{
	while (stack_length(stack->a) > 2)
		s_push_b(stack);
	if (stack->a->value > stack->a->next->value)
		s_swap_a(stack);
	while (stack->b)
		insert(stack);
}
