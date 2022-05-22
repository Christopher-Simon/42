/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:09:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/22 08:51:29 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack	*swap_a(t_stack *a)
{
	t_stack *ptr;

	ptr = a;
	a = a->next;
	ptr->next = a->next;
	a->next = ptr;
	a->begin = 1;
	ptr->begin = 0;
	return (a);
}

// swap_b

// push_a

t_stack	*push_b(t_stack **a, t_stack *b)
{
	t_stack	*ptr;

	ptr = *a;
	ptr->next = b;
	a = a->next;
	// a->begin = 1;
	printf("\n%d\n", ptr->value);
	if (b)
		b->begin = 0;
	return (ptr);
}
