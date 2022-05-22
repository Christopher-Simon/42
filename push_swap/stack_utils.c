/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:34:03 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/21 22:02:41 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack *ft_begin(int d)
{
	t_stack	*root;

	root = malloc(sizeof(t_stack));
	if (!root)
		return (0);
	root->value = d;
	root->begin = 1;
	root->next = NULL;
	return(root);
}

void	ft_stack_new(t_stack *ptr, int d)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = d;
	new->begin = 0;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = new;
}

void	print_stack(t_stack *a, t_stack *b)
{
	printf("a    b\n");
	while (a != NULL || b != NULL)
	{
		if (a)
		{
			printf("%-5d", a->value);
			a = a->next;
		}
		if (b)
		{
			printf("%d", b->value);
			b = b->next;
		}
		printf("\n");
	}
	printf("\n");
}
