/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:34:03 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 17:38:54 by chsimon          ###   ########.fr       */
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

void	free_stack(t_full_stack *stack)
{
	t_stack	*root;

	root = stack->a;
	stack->a = stack->a->next;
	while (stack->a->next->begin != 1)
		stack->a = stack->a->next;
	stack->a->next = NULL;
	stack->a = root;
	while (root != NULL)
	{
		root = root->next;
		free(stack->a);
		stack->a = root;
	}
	free(stack);
}

// void	print_stack(t_full_stack *stack)
// {
// 	int	end_a = 0;
// 	int	end_b = 0;

// 	ft_printf("a    b\n");
// 	if (stack->a)
// 	{
// 		ft_printf("%-5d", stack->a->value);
// 		stack->a = stack->a->next;
// 	}
// 	else
// 		ft_printf("     ");
// 	if (stack->b)
// 	{
// 		ft_printf("%d", stack->b->value);
// 		stack->b = stack->b->next;
// 	}
// 	ft_printf("\n");
// 	while ((end_a == 0 || end_b == 0))
// 	{
// 		if (stack->a && stack->a->begin != 1)
// 		{
// 			ft_printf("%-5d", stack->a->value);
// 			stack->a = stack->a->next;
// 		}
// 		else
// 		{
// 			ft_printf("     ");
// 			end_a = 1;
// 		}
// 		if (stack->b && stack->b->begin != 1)
// 		{
// 			ft_printf("%d", stack->b->value);
// 			stack->b = stack->b->next;
// 		}
// 		else
// 			end_b = 1;
// 		ft_printf("\n");
// 	}
// }
