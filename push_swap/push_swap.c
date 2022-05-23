/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/23 09:30:35 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

void	insert_bt(t_full_stack *stack)
{
	while (stack->a->next->value > 
		stack->a->next->next->value)
	{
		push_b(stack);
		swap_a(stack);
	}
	if (stack->a->value > stack->a->next->value)
		insert_bt(stack);
	push_a(stack);
}

void	insert(t_full_stack *stack)
{
	push_a(stack);
	if (stack->a->value > stack->a->next->value)
		swap_a(stack);
	if (stack->a->next->value > 
		stack->a->next->next->value)
	insert_bt(stack);
}

void	algo(t_full_stack *stack)
{
	while (stack_length(stack->a) > 2)
		push_b(stack);
	if (stack->a->value > stack->a->next->value)
		swap_a(stack);
	while (stack->b)
		insert(stack);
}

int	main(int argc,char **argv)
{
	t_full_stack	*stack;
	int	i;
	
	i = 0;
	stack = malloc(sizeof(t_full_stack));
	ft_begin(stack, ft_atoi(argv[++i]));
	while (i++ < argc - 1)
		ft_stack_new(stack, ft_atoi(argv[i]));
	print_stack(stack);
	algo(stack);
	// printf("length : %d\n",stack_length(stack->a));
	print_stack(stack);
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