/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:55:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/25 18:39:24 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	median(t_full_stack *stack)
{
	t_full_stack	*med_stack;
	t_stack			*root;
	int				i;

	i = 0;
	med_stack = malloc(sizeof(t_full_stack));
	if (!med_stack)
		return (0);
	ft_begin(med_stack, stack->a->value);
	stack->a = stack->a->next;
	while (stack->a->begin != 1)
	{
		// printf("%d\n", stack->a->value);
		ft_stack_new(med_stack, stack->a->value);
		stack->a = stack->a->next;
	}
	root = med_stack->a;
	// print_stack(med_stack);
	low_algo(med_stack);
	// print_stack(med_stack);
	while 	( i++ < stack_length(stack->a)/2)
	{
		med_stack->a = med_stack->a->next;
	}
	i = med_stack->a->value;
	med_stack->a = root;
	free_stack(med_stack);
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

t_ppdpg	send_min(t_full_stack *stack)
{
	t_ppdpg	min;
	t_stack *ptr;
	int		index;

	ptr = stack->a;
	min.value = ptr->value;
	index = 1;
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		index++;
		if (min.value > ptr->value)
		{
			min.index = index;
			min.value = ptr->value;
		}
		ptr = ptr->next;
	}
	return (min);
}
