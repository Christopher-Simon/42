/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:55:05 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/23 20:11:08 by chsimon          ###   ########.fr       */
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
	algo(med_stack);
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