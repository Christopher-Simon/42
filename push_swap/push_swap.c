/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/23 20:39:13 by chsimon          ###   ########.fr       */
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
	// printf("%d\n", median(stack));
	free_stack(stack);


	// print_stack(stack);
	// printf("order ? : %d\n", check_order(stack));
	// print_stack(stack);


	
	// swap_a(stack);
	// print_stack(stack);
	// swap_a(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// swap_b(stack);
	// print_stack(stack);
	// swap_b(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// swap_b(stack);
	// print_stack(stack);
	// swap_b(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// push_b(stack);
	// print_stack(stack);
	// while (stack->a)
	// {
	// 	push_b(stack);
	// 	print_stack(stack);
	// // }
	// while (stack->b)
	// {
	// 	push_a(stack);
	// 	print_stack(stack);
	// }
	// rotate_a(stack);
	// print_stack(stack);	
	// rotate_b(stack);
	// print_stack(stack);
	// rotate_b(stack);
	// print_stack(stack);
	// rotate_b(stack);
	// print_stack(stack);
	// rotate_b(stack);
	// print_stack(stack);
	// reverse_rotate_a(stack);
	// print_stack(stack);
	// reverse_rotate_b(stack);
	// print_stack(stack);
	return (0);
}