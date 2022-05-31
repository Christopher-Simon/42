/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:34:03 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 14:54:08 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	stack_length(t_stack *lst)
{
	int		i;
	t_stack	*ptr;

	ptr = lst;
	i = 1;
	while (ptr->next->begin != 1)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

int	check_order(t_full_stack *stack)
{
	t_stack	*root;

	if (!stack->a)
	{
		ft_printf("Error\n");
		free_stack(stack);
		exit (1);
	}
	root = stack->a;
	if (root->next->begin == 1)
		return (1);
	while (root->value < root->next->value)
	{
		root = root->next;
		if (root->next->begin == 1)
			return (1);
	}
	return (0);
}

void	free_mini_stack(t_stack *stack)
{
	t_stack	*root_a;

	root_a = stack;
	stack = stack->next;
	while (stack->next->begin != 1)
		stack = stack->next;
	stack->next = NULL;
	stack = root_a;
	while (root_a != NULL)
	{
		root_a = root_a->next;
		free(stack);
		stack = root_a;
	}
}

void	free_stack(t_full_stack *stack)
{
	if (stack->a)
		free_mini_stack(stack->a);
	if (stack->b)
		free_mini_stack(stack->b);
	free(stack);
}

void	print_stack(t_full_stack *stack)
{
	int	end_a = 0;
	int	end_b = 0;

	ft_printf("a    b\n");
	if (stack->a)
	{
		ft_printf("%-5d", stack->a->value);
		stack->a = stack->a->next;
	}
	else
		ft_printf("     ");
	if (stack->b)
	{
		ft_printf("%d", stack->b->value);
		stack->b = stack->b->next;
	}
	ft_printf("\n");
	while ((end_a == 0 || end_b == 0))
	{
		if (stack->a && stack->a->begin != 1)
		{
			ft_printf("%-5d", stack->a->value);
			stack->a = stack->a->next;
		}
		else
		{
			ft_printf("     ");
			end_a = 1;
		}
		if (stack->b && stack->b->begin != 1)
		{
			ft_printf("%d", stack->b->value);
			stack->b = stack->b->next;
		}
		else
			end_b = 1;
		ft_printf("\n");
	}
}
