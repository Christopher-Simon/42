/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/27 15:46:55 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

// Check overflow long int 

int	main(int argc, char **argv)
{
	t_full_stack	*stack;
	int				i;

	i = 0;
	if (argc <= 1)
		return (0);
	if (!verif(argv))
	{
		printf("No");	
		return (0);
	}
	else
	{
		printf("Yes");	
		return (0);
	}
	stack = malloc(sizeof(t_full_stack));
	if (!stack)
		return (0);
	ft_begin(stack, ft_atoi(argv[++i]));
		while (i++ < argc - 1)
			ft_stack_new(stack, ft_atoi(argv[i]));
	// if (check_order(stack))
	// 	return (0);
	// if (stack_length(stack->a) == 2)
	// {
	// 	if (stack->a->value > stack->a->next->value)
	// 		swap_a(stack);
	// }
	// else if (stack_length(stack->a) == 3)
	// 	sort_3(stack);
	// else
	// 	algo(stack);



	
	// print_stack(stack);
	// swap_a(stack);
	// print_stack(stack);
	// push_b(stack);
	// push_b(stack);
	// push_b(stack);
	// print_stack(stack);
	// rotate_a(stack);
	// rotate_b(stack);
	// // rr(stack);
	// print_stack(stack);
	// reverse_rotate_a(stack);
	// reverse_rotate_b(stack);
	// // rrr(stack);
	// print_stack(stack);
	// swap_a(stack);
	// print_stack(stack);
	// push_a(stack);
	// push_a(stack);
	// push_a(stack);
	// print_stack(stack);
	// printf("%d",check_order(stack));
	free_stack(stack);

	// for_b_find_direct_above(stack->b->value, stack);
	// selection(stack);


	// t_ppdpg	min;
	// min = send_min(stack);
	// print_stack(stack);
	// get_to_end(stack);
	// printf("index %d val %d", min.index, min.value);
	// get_min()
	// push_b(stack);

	// print_stack(stack);
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