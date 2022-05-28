/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:09:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/23 20:23:02 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	s_swap_a(t_full_stack *stack)
{
	t_stack	*root;
	t_stack	*pos_1;
	t_stack	*pos_2;

	root = stack->a->next;
	pos_1 = stack->a;
	pos_2 = root->next;
	root->next = pos_1;
	pos_1->next = pos_2;
	while (stack->a->next->begin != 1)
		stack->a = stack->a->next;
	stack->a->next = root;
	stack->a = root;
	root->begin = 1;
	pos_1->begin = 0;
}

void	s_swap_b(t_full_stack *stack)
{
	t_stack	*root;
	t_stack	*pos_1;
	t_stack	*pos_2;

	root = stack->b->next;
	pos_1 = stack->b;
	pos_2 = root->next;
	root->next = pos_1;
	pos_1->next = pos_2;
	while (stack->b->next->begin != 1)
		stack->b = stack->b->next;
	stack->b->next = root;
	stack->b = root;
	root->begin = 1;
	pos_1->begin = 0;
}

void	s_push_a(t_full_stack *stack)
{
	t_stack	*new_root;

	new_root = stack->b;
	if (stack->b == stack->b->next)
		stack->b = NULL;
	else
		stack->b = remove_root(stack->b->next);
	stack->a = add_root(stack->a, new_root);
}

void	s_push_b(t_full_stack *stack)
{
	t_stack	*new_root;

	new_root = stack->a;
	if (stack->a == stack->a->next)
		stack->a = NULL;
	else
		stack->a = remove_root(stack->a->next);
	stack->b = add_root(stack->b, new_root);
}

void	s_rotate_a(t_full_stack *stack)
{
	stack->a->begin = 0;
	stack->a->next->begin = 1;
	stack->a = stack->a->next;
}

void	s_rotate_b(t_full_stack *stack)
{
	stack->b->begin = 0;
	stack->b->next->begin = 1;
	stack->b = stack->b->next;
}

void	s_reverse_rotate_a(t_full_stack *stack)
{
	t_stack	*old_root;

	old_root = stack->a;
	while (stack->a->next->begin != 1)
		stack->a = stack->a->next;
	stack->a->begin = 1;
	old_root->begin = 0;
}

void	s_reverse_rotate_b(t_full_stack *stack)
{
	t_stack	*old_root;

	old_root = stack->b;
	while (stack->b->next->begin != 1)
		stack->b = stack->b->next;
	stack->b->begin = 1;
	old_root->begin = 0;
}
