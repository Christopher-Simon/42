/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:55:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 12:19:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_med_stack(t_full_stack *med_stack)
{
	while (med_stack->a->begin != 1)
		med_stack->a = med_stack->a->next;
	free_stack(med_stack);
}

int	init_median(t_full_stack *med_stack, t_full_stack *stack)
{
	t_stack	*ptr;

	ptr = stack->a;
	if (!ft_begin(med_stack, ptr->value))
	{
		free_med_stack(med_stack);
		free_stack(stack);
		return (0);
	}
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		if (!ft_stack_new(med_stack, ptr->value))
		{
			free_med_stack(med_stack);
			free_stack(stack);
			return (0);
		}
		ptr = ptr->next;
	}
	return (1);
}

int	median(t_full_stack *stack, int *med)
{
	t_full_stack	*med_stack;
	int				i;

	i = 0;
	med_stack = malloc(sizeof(t_full_stack));
	if (!med_stack)
	{
		free_stack(stack);
		return (0);
	}
	if (!init_median(med_stack, stack))
		return (0);
	low_algo(med_stack);
	while (i++ < stack_length(stack->a) / 2)
		med_stack->a = med_stack->a->next;
	i = med_stack->a->value;
	free_med_stack(med_stack);
	*med = i;
	return (1);
}

int	get_median(t_full_stack *stack)
{
	int	med;
	int	half;
	int	even;

	even = 1;
	if (stack_length(stack->a) % 2 == 0)
		even = 0;
	half = stack_length(stack->a) / 2;
	if (!median(stack, &med))
		return (0);
	while (stack_length(stack->a) != half + even)
	{
		if (stack->a->value < med)
			push_b(stack, 0);
		else
			rotate_a(stack, 0);
	}
	return (1);
}
