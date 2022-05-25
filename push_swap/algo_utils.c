/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:11:43 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/25 11:12:28 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_3(t_full_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a < b && b < c)
		return ;
	if (a < b && b > c)
	{
		if (a > c)
			reverse_rotate_a(stack);
		else 
		{
			swap_a(stack);
			rotate_a(stack);			
		}
	}
	if (a > b && b < c)
	{
		if (a > c)
			rotate_a(stack);
		else
			swap_a(stack);
	}
	if (a > b && b > c)
	{
		rotate_a(stack);
		swap_a(stack);
	}
}

void	get_median(t_full_stack *stack)
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