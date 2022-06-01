/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:09:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 17:38:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_b(t_full_stack *stack, int silent)
{
	t_stack	*new_root;

	if (!stack->a)
		return ;
	if (!silent)
		ft_printf("pb\n");
	new_root = stack->a;
	if (stack->a == stack->a->next)
		stack->a = NULL;
	else
		stack->a = remove_root(stack->a->next);
	stack->b = add_root(stack->b, new_root);
}

void	rotate_a(t_full_stack *stack, int silent)
{
	if (!stack->a)
		return ;
	if (!silent)
		ft_printf("ra\n");
	stack->a->begin = 0;
	stack->a->next->begin = 1;
	stack->a = stack->a->next;
}

void	rotate_b(t_full_stack *stack, int silent)
{
	if (!stack->b)
		return ;
	if (!silent)
		ft_printf("rb\n");
	stack->b->begin = 0;
	stack->b->next->begin = 1;
	stack->b = stack->b->next;
}

void	reverse_rotate_a(t_full_stack *stack, int silent)
{
	t_stack	*old_root;

	if (!stack->a)
		return ;
	if (!silent)
		ft_printf("rra\n");
	old_root = stack->a;
	while (stack->a->next->begin != 1)
		stack->a = stack->a->next;
	stack->a->begin = 1;
	old_root->begin = 0;
}

void	reverse_rotate_b(t_full_stack *stack, int silent)
{
	t_stack	*old_root;

	if (!stack->b)
		return ;
	if (!silent)
		ft_printf("rrb\n");
	old_root = stack->b;
	while (stack->b->next->begin != 1)
		stack->b = stack->b->next;
	stack->b->begin = 1;
	old_root->begin = 0;
}
