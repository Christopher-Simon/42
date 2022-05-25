/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/25 18:45:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_full_stack	*stack;
	int				i;

	i = 0;
	if (argc <= 1)
		return (0);
	stack = malloc(sizeof(t_full_stack));
	if (!stack)
		return (0);
	ft_begin(stack, ft_atoi(argv[++i]));
	while (i++ < argc - 1)
		ft_stack_new(stack, ft_atoi(argv[i]));
	algo(stack);
	// t_ppdpg	min;
	// min = send_min(stack);
	// print_stack(stack);
	// get_to_end(stack);
	// printf("index %d val %d", min.index, min.value);
	// get_min()
	// push_b(stack);
	// print_stack(stack);
	// for_b_find_direct_above(stack->b->value, stack);
	// selection(stack);

	
	free_stack(stack);



	// swap_a(stack);
	// print_stack(stack);
	// push_b(stack);
	// push_b(stack);
	// print_stack(stack);
	// // rotate_a(stack);
	// // rotate_b(stack);
	// rr(stack);
	// print_stack(stack);
	// // reverse_rotate_a(stack);
	// // reverse_rotate_b(stack);
	// rrr(stack);
	// print_stack(stack);
	// swap_a(stack);
	// print_stack(stack);
	// push_a(stack);
	// push_a(stack);
	// push_a(stack);
	// print_stack(stack);
	return (0);
}