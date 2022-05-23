/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:52:37 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/23 18:52:49 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	insert_bt(t_full_stack *stack)
{
	push_b(stack);
	swap_a(stack);
	if (stack->a->next->value > 
		stack->a->next->next->value 
		&& stack_length(stack->a) > 2)
		insert_bt(stack);
	push_a(stack);
}

void	insert(t_full_stack *stack)
{
	push_a(stack);
	if (stack->a->value > stack->a->next->value)
		swap_a(stack);
	if (stack->a->next->value > 
		stack->a->next->next->value)
	insert_bt(stack);
}

void	algo(t_full_stack *stack)
{
	while (stack_length(stack->a) > 2)
		push_b(stack);
	if (stack->a->value > stack->a->next->value)
		swap_a(stack);
	while (stack->b)
		insert(stack);
}