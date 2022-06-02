/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:32:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 12:23:13 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	get_count(t_full_stack *stack, int index_a, int index_b, int flag)
{
	t_move	move;

	move.ra = index_a - 1;
	if (move.ra == 0)
		move.rra = 0;
	else
		move.rra = stack_length(stack->a) - move.ra;
	move.rb = index_b - 1;
	if (move.rb == 0)
		move.rrb = 0;
	else
		move.rrb = stack_length(stack->b) - move.rb;
	get_min(&move.ra, &move.rra);
	get_min(&move.rb, &move.rrb);
	if (flag == 1)
	{
		execut_order_66(stack, move);
		return (1);
	}
	return (count_value(move));
}

t_combi	selection(t_full_stack *stack, int index_b, int count)
{
	t_ppdpg	ppdpg;
	t_combi	combi;
	t_stack	*ptr_b;

	ptr_b = stack->b;
	ppdpg.index = for_b_find_direct_above(ptr_b->value, stack);
	count = get_count(stack, ppdpg.index, index_b, 0);
	combi.index_ppdpg = ppdpg.index;
	combi.index_b = index_b;
	index_b++;
	ptr_b = ptr_b->next;
	while (ptr_b->begin != 1)
	{
		ppdpg.index = for_b_find_direct_above(ptr_b->value, stack);
		if (count > get_count(stack, ppdpg.index, index_b, 0))
		{
			combi.index_ppdpg = ppdpg.index;
			combi.index_b = index_b;
			count = get_count(stack, ppdpg.index, index_b, 0);
		}
		ptr_b = ptr_b->next;
		index_b++;
	}
	return (combi);
}

void	get_to_end(t_full_stack *stack)
{
	t_ppdpg	min;

	min = send_min(stack);
	if (min.index < stack_length(stack->a))
	{
		while (stack->a->value != min.value)
			rotate_a(stack, 0);
	}
	else
	{
		while (stack->a->value != min.value)
			reverse_rotate_a(stack, 0);
	}
}

int	algo(t_full_stack *stack)
{
	int		max;
	t_combi	combi;

	if (!get_median(stack))
		return (0);
	max = get_max(stack->a);
	while (stack_length(stack->a) > 3)
	{
		if (stack->a->value != max)
			push_b(stack, 0);
		else
			rotate_a(stack, 0);
	}
	sort_3(stack);
	while (stack->b)
	{
		combi = selection(stack, 1, 0);
		get_count(stack, combi.index_ppdpg, combi.index_b, 1);
	}
	get_to_end(stack);
	return (1);
}