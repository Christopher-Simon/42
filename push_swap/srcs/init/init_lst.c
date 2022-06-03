/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:06:01 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 14:38:59 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_stack_new(t_full_stack *stack, int d)
{
	t_stack	*new;
	t_stack	*root;

	root = stack->a;
	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(stack);
		return (0);
	}
	new->value = d;
	new->begin = 0;
	new->next = root;
	while (stack->a->next != root)
		stack->a = stack->a->next;
	stack->a->next = new;
	while (stack->a != root)
		stack->a = stack->a->next;
	return (1);
}

int	ft_begin(t_full_stack *stack, int d)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack));
	if (!a)
	{
		free_stack(stack);
		return (0);
	}
	a->value = d;
	a->begin = 1;
	a->next = a;
	b = NULL;
	stack->a = a;
	stack->b = b;
	return (1);
}

t_full_stack	*init_lst(int argc, char **argv)
{
	t_full_stack	*stack;
	int				i;

	i = 0;
	stack = malloc(sizeof(t_full_stack));
	if (!stack)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	if (!ft_begin(stack, ft_atol(argv[++i], stack)))
		return (NULL);
	while (i++ < argc - 1)
	{
		if (!ft_stack_new(stack, ft_atol(argv[i], stack)))
			return (NULL);
	}
	return (stack);
}
