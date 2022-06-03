/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_above.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:26:56 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/25 18:01:22 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	for_b_find_direct_above(int b, t_full_stack *stack)
{
	t_stack	*ptr;
	t_ppdpg	r;
	int		index_a;

	r.value = get_max(stack->a);
	index_a = 1;
	ptr = stack->a;
	if (ptr->value > b && ptr->value <= r.value)
	{
		r.value = ptr->value;
		r.index = index_a;
	}
	index_a++;
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		if (ptr->value > b && ptr->value <= r.value)
		{
			r.value = ptr->value;
			r.index = index_a;
		}
		index_a++;
		ptr = ptr->next;
	}
	return (r.index);
}
