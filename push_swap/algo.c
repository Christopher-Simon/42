/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:32:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/23 23:31:47 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	get_mediane(t_full_stack *stack)
{
	int	med;
	int	half;
	int	even;
	
	even = 1;
	if (stack_length(stack->a) % 2 == 0)
		even = 0;
	half = stack_length(stack->a) / 2;
	med = median(stack);
	while (stack_length(stack->a) != half + even)
	{
		if (stack->a->value < med)
			push_b(stack);
		else
			rotate_a(stack);
	}
	while (stack->a->begin != 1)
		stack->a = stack->a->next;
}

void	counting(t_full_stack *stack)
{
	
}

void	algo(t_full_stack *stack)
{
	get_mediane(stack);
	print_stack(stack);
	while (stack_length(stack->a) > 3)
		push_b(stack);
	counting(stack);
	print_stack(stack);
}