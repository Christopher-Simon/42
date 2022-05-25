/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:32:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/25 09:17:53 by chsimon          ###   ########.fr       */
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

si chosen rra & rrb	
	rrr while
si chosen ra & rb	
	rr while
chosen ra & rrb
chosen rra & rb
	
int	get_count(t_full_stack *stack, int index_a, int index_b)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;


	ra = index_a - 1;
	if (ra == 0)
		rra = 0;
	else
		rra = stack_length(stack->a) - ra;
	rb = index_b - 1;
	if (rb == 0)
		rrb = 0;
	else
		rrb = stack_length(stack->b) - rb;
	printf("ra :%d rra : %d rb : %d rrb : %d\n", ra, rra, rb, rrb);
	
	if (stack_length(stack->a) <= stack_length(stack->b))
	{
		if (rb < rrb)
			rrb = 0;
		else
			rb = 0;
		if (rrb)
			ra = 0;
		else
			rra = 0;
	printf("ra :%d rra : %d rb : %d rrb : %d\n", ra, rra, rb, rrb);
	}

	printf("%d\n", rra + rrb + ra + rb);
	return(1);
}

void	counting(t_full_stack *stack)
{

	int	ppdpg;
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	int	index_a;
	int	index_b;

	index_a = 1;
	index_b = 1;
	ptr_a = stack->a;
	ptr_b = stack->b;
	ppdpg = stack->a->value;
	while (ptr_a->value < ptr_b->value)
	{
		index_a++;
		ptr_a = ptr_a->next;
	}
	ppdpg = ptr_a->value;
	get_count(stack, index_a, index_b);
	printf("val_b : %d ppdpg : %d index_a : %d index_b : %d\n", ptr_b->value, ppdpg, index_a, index_b);

	ptr_b = ptr_b->next;
	

	while (ptr_b->begin != 1)
	{
		ppdpg = stack->a->value;
		ptr_a = stack->a;
		index_a = 1;
		while (ptr_a->value < ptr_b->value)
		{
			index_a++;
			ptr_a = ptr_a->next;
		}
		ppdpg = ptr_a->value;
		index_b++;
		get_count(stack, index_a, index_b);
		printf("val_b : %d ppdpg : %d index_a : %d index_b : %d\n", ptr_b->value, ppdpg, index_a, index_b);
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
