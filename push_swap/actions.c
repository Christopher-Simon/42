/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:09:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/22 19:09:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap_a(t_full_stack *stack)
{
	t_stack	*root;
	t_stack	*pos_1;
	t_stack	*pos_2;

	printf("sa\n");
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

void	swap_b(t_full_stack *stack)
{
	t_stack	*root;
	t_stack	*pos_1;
	t_stack	*pos_2;

	printf("sb\n");
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

t_stack	*remove_root(t_stack *lst)
{
	t_stack	*root;

	root = lst;
	root->begin = 1;
	while (lst->next->begin != 1)
		lst = lst->next;
	return (lst->next = root);
}

t_stack	*add_root(t_stack *lst, t_stack *root)
{
	root->begin = 1;
	if (!lst)
		return (root->next = root);
	else
	{
		root->next = lst;
		while (lst->next->begin != 1)
			lst = lst->next;
		lst->next->begin = 0;
		return (lst->next = root);
	}
	return (0);
}

void	push_a(t_full_stack *stack)
{
	t_stack	*new_root;

	printf("pa\n");
	new_root = stack->b;
	if (stack->b == stack->b->next)
		stack->b = NULL;
	else
		stack->b = remove_root(stack->b->next);
	stack->a = add_root(stack->a, new_root);
}

void	push_b(t_full_stack *stack)
{
	t_stack	*new_root;

	printf("pb\n");
	new_root = stack->a;
	if (stack->a == stack->a->next)
		stack->a = NULL;
	else
		stack->a = remove_root(stack->a->next);
	stack->b = add_root(stack->b, new_root);
}

void	rotate_a(t_full_stack *stack)
{
	
}
