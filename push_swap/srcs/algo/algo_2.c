/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:32:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 18:46:19 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	execut_order_66_2(t_full_stack *stack, t_move *move)
{
	if (move->ra && move->rb)
	{
		move->ra--;
		move->rb--;
		rr(stack, 0);
	}
	else if (move->ra)
	{
		move->ra--;
		rotate_a(stack, 0);
	}
	else if (move->rb)
	{
		move->rb--;
		rotate_b(stack, 0);
	}
}

void	execut_order_66(t_full_stack *stack, t_move move)
{
	while (move.ra || move.rb || move.rra || move.rrb)
	{
		if (move.rra && move.rrb)
		{
			move.rra--;
			move.rrb--;
			rrr(stack, 0);
		}
		else if (move.rra)
		{
			move.rra--;
			reverse_rotate_a(stack, 0);
		}
		else if (move.rrb)
		{
			move.rrb--;
			reverse_rotate_b(stack, 0);
		}
		execut_order_66_2(stack, &move);
	}
	push_a(stack, 0);
}

int	count_value_2(t_move *move, int count)
{
	if (move->ra && move->rb)
	{
		move->ra--;
		move->rb--;
		count++;
	}
	else if (move->ra)
	{
		move->ra--;
		count++;
	}
	else if (move->rb)
	{
		move->rb--;
		count++;
	}
	return (count);
}

int	count_value(t_move move)
{
	int	count;

	count = 0;
	while (move.ra || move.rb || move.rra || move.rrb)
	{
		if (move.rra && move.rrb)
		{
			move.rra--;
			move.rrb--;
			count++;
		}
		else if (move.rra)
		{
			move.rra--;
			count++;
		}
		else if (move.rrb)
		{
			move.rrb--;
			count++;
		}
		count = count_value_2(&move, count);
	}
	return (count);
}
