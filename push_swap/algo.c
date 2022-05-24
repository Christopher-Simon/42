/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:32:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/24 18:18:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	stack = stack->next;
	while (stack->begin != 1)
	{
		if (max < stack->value)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	counting(t_full_stack *stack)
{
	// int	ra
	// int	rb
	// int	rra
	// int	rrb
	// int	index_a;
	// int	index_b;
	int	ppdpg;
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	// ra = stack_length(stack_a) - index_a;
	// rra = stack_length(stack_a) - ra;
	// rb = stack_length(stack_b) - index_b;
	// rrb = stack_length(stack_b) - ra;

	ptr_a = stack->a;
	ptr_b = stack->b;
	ppdpg = stack->a->value;
	while (ptr_a->value < ptr_b->value)
		ptr_a = ptr_a->next;
	ppdpg = ptr_a->value;
	printf("val_b : %d ppdpg : %d\n", ptr_b->value, ppdpg);

	ptr_b = ptr_b->next;
	

	while (ptr_b->begin != 1)
	{
		ppdpg = stack->a->value;
		ptr_a = stack->a;
		while (ptr_a->value < ptr_b->value)
			ptr_a = ptr_a->next;
		ppdpg = ptr_a->value;
		printf("val_b : %d ppdpg : %d\n", ptr_b->value, ppdpg);
		ptr_b = ptr_b->next;
	}
	// stack length
	// index
	// nb r = stack_length - index
	// nb rr = stack_length - r
	// Pour a et b 
	// Lier : 
	// a->value 
}

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

void	algo(t_full_stack *stack)
{
	int	max;

	get_median(stack);
	max = get_max(stack->a);
	while (stack_length(stack->a) > 3)
	{
		if (stack->a->value != max)
			push_b(stack);
		else
			rotate_a(stack);
	}
	sort_3(stack);
	print_stack(stack);
	counting(stack);
}
