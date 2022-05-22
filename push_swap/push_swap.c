/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/22 19:00:58 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

int	main(void)
{
	int				tab[] = {5,15,20,30};
	int 			count;
	t_full_stack	*stack;

	count = 0;
	stack = malloc(sizeof(t_full_stack));
	ft_begin(stack, tab[count]);
	while (count++ < 3)
		ft_stack_new(stack, tab[count]);
	print_stack(stack);
	swap_a(stack);
	print_stack(stack);
	push_b(stack);
	print_stack(stack);
	push_b(stack);
	print_stack(stack);
	swap_b(stack);
	print_stack(stack);
	swap_b(stack);
	print_stack(stack);
	push_b(stack);
	print_stack(stack);
	swap_b(stack);
	print_stack(stack);
	swap_b(stack);
	print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// while (stack->a)
	// {
	// 	push_b(stack);
	// 	print_stack(stack);
	// }
	while (stack->b)
	{
		push_a(stack);
		print_stack(stack);
	}
	return (0);
}