/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:32:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/26 15:54:42 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	execut_order_66(t_full_stack *stack, int ra, int rb, int rra, int rrb)
{
	// printf("ra : %d,rb : %d,rra : %d,rrb : %d\n", ra, rb, rra, rrb);
	while (ra || rb || rra || rrb)
	{
		if (rra && rrb)
		{
			rra--;	
			rrb--;	
			rrr(stack);
		}
		else if (rra)
		{
			rra--;
			reverse_rotate_a(stack);
		}
		else if (rrb)
		{
			rrb--;			
			reverse_rotate_b(stack);
		}
		if (ra && rb)
		{
			ra--;
			rb--;
			rr(stack);
		}
		else if (ra)
		{
			ra--;
			rotate_a(stack);
		}
		else if (rb)
		{
			rb--;
			rotate_b(stack);
		}
	}
	push_a(stack);
}

int	count_value(int ra, int rb, int rra, int rrb)
{
	int	count;

	count = 0;
	while (ra || rb || rra || rrb)
	{
		if (rra && rrb)
		{
			rra--;	
			rrb--;	
			count++;
		}
		else if (rra)
		{
			rra--;
			count++;
		}
		else if (rrb)
		{
			rrb--;			
			count++;
		}
		if (ra && rb)
		{
			ra--;
			rb--;
			count++;
		}
		else if (ra)
		{
			ra--;
			count++;
		}
		else if (rb)
		{
			rb--;
			count++;
		}
	}
	return (count);
}

int	get_count(t_full_stack *stack, int index_a, int index_b, int flag)
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
	// printf("ra :%d rra : %d rb : %d rrb : %d\n", ra, rra, rb, rrb);
	get_min(&ra, &rra);
	get_min(&rb, &rrb);
	if (flag == 1)
		execut_order_66(stack, ra, rb, rra, rrb);
	// printf("count : %d\n", count_value(ra, rb, rra, rrb));
	// printf("%dra :%d rra : %d rb : %d rrb : %d\n", flag, ra, rra, rb, rrb);
	return(count_value(ra, rb, rra, rrb));
	// return (1);
}


t_combi	selection(t_full_stack *stack)
{
	t_ppdpg	ppdpg;
	t_combi	combi;
	t_stack	*ptr_b;
	int		index_b;
	int		count;

	ptr_b = stack->b;
	index_b = 1;
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
	// printf("combi. ppdpg_index %d b_index %d count %d\n", combi.index_ppdpg, combi.index_b, count);
	return (combi);
}

void	get_to_end(t_full_stack *stack)
{
	t_ppdpg min;
		
	min = send_min(stack);
	if (min.index < stack_length(stack->a))
	{
		while (stack->a->value != min.value)
			rotate_a(stack);
	}
	else
	{
		while (stack->a->value != min.value)
			reverse_rotate_a(stack);
	}
}

void	algo(t_full_stack *stack)
{
	int		max;
	t_combi	combi;

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
	while (stack->b)
	{
		combi = selection(stack);
		get_count(stack, combi.index_ppdpg, combi.index_b, 1);
	}
	get_to_end(stack);
}
