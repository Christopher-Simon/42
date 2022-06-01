/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:52:37 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 16:11:42 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	insert_bt(t_full_stack *stack)
{
	push_b(stack, 1);
	swap_a(stack, 1);
	if (stack->a->next->value
		> stack->a->next->next->value
		&& stack_length(stack->a) > 2)
		insert_bt(stack);
	push_a(stack, 1);
}

void	insert(t_full_stack *stack)
{
	push_a(stack, 1);
	if (stack->a->value > stack->a->next->value)
		swap_a(stack, 1);
	if (stack->a->next->value
		> stack->a->next->next->value)
		insert_bt(stack);
}

void	low_algo(t_full_stack *stack)
{
	while (stack_length(stack->a) > 2)
		push_b(stack, 1);
	if (stack->a->value > stack->a->next->value)
		swap_a(stack, 1);
	while (stack->b)
		insert(stack);
}
