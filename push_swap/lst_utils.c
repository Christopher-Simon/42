/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:34:03 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/19 10:42:00 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap"

s_stack *ft_stack_begin(int d)
{
	t_list	*root;

	root = malloc(sizeof(t_stack_a));
	if (!root)
		return (0);
	root->value = d;
	root->begin = 1;
	root->next = NULL;
	return (root);
}

s_stack *ft_stack_new(int d)
{
	t_list	*root;

	root = malloc(sizeof(t_stack));
	if (!root)
		return (0);
	root->value = d;
	root->begin = 0;
	root->next = NULL;
	return (root);
}

s_stack *ft_stack_to_front(int d)
{
	t_list	*root;

	root = malloc(sizeof(t_stack));
	if (!root)
		return (0);
	root->value = d;
	root->begin = 0;
	root->next = NULL;
	return (root);
}