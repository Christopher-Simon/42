/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:11:43 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 11:55:35 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_3_part2(int a, int c, t_full_stack *stack)
{
	if (a > c)
		reverse_rotate_a(stack, 0);
	else
	{
		swap_a(stack, 0);
		rotate_a(stack, 0);
	}
}

void	sort_3(t_full_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->value;
	b = stack->a->next->value;
	c = stack->a->next->next->value;
	if (a < b && b < c)
		return ;
	if (a < b && b > c)
	{
		sort_3_part2(a, c, stack);
	}
	else if (a > b && b < c)
	{
		if (a > c)
			rotate_a(stack, 0);
		else
			swap_a(stack, 0);
	}
	else if (a > b && b > c)
	{
		rotate_a(stack, 0);
		swap_a(stack, 0);
	}
}

t_ppdpg	send_min(t_full_stack *stack)
{
	t_ppdpg	min;
	t_stack	*ptr;
	int		index;

	ptr = stack->a;
	min.value = ptr->value;
	index = 1;
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		index++;
		if (min.value > ptr->value)
		{
			min.index = index;
			min.value = ptr->value;
		}
		ptr = ptr->next;
	}
	return (min);
}

void	get_min(int *a, int *b)
{
	if (*a > *b)
		*a = 0;
	else
		*b = 0;
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*ptr;

	ptr = stack;
	max = ptr->value;
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		if (max < ptr->value)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}
