/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:55:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 16:20:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_med_stack(t_full_stack *med_stack)
{
	while (med_stack->a->begin != 1)
		med_stack->a = med_stack->a->next;
	free_stack(med_stack);
}

int	median(t_full_stack *stack)
{
	t_full_stack	*med_stack;
	t_stack			*ptr;
	int				i;

	i = 0;
	ptr = stack->a;
	med_stack = malloc(sizeof(t_full_stack));
	if (!med_stack)
		return (0);
	ft_begin(med_stack, ptr->value);
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		ft_stack_new(med_stack, ptr->value);
		ptr = ptr->next;
	}
	low_algo(med_stack);
	while (i++ < stack_length(stack->a) / 2)
	{
		med_stack->a = med_stack->a->next;
	}
	i = med_stack->a->value;
	free_med_stack(med_stack);
	return (i);
}

void	get_min(int *a, int *b)
{
	if (*a > *b)
		*a = 0;
	else
		*b = 0;
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*ptr;

	ptr = stack;
	max = ptr->value;
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		if (max < ptr->value)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
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
			push_b(stack, 0);
		else
			rotate_a(stack, 0);
	}
}
