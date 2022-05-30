/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:25:47 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 17:38:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdlib.h>

int	post_init_check(t_full_stack *stack)
{
	if (!check_double(stack))
	{
		ft_printf("Error\n");
		exit (1);
	}
	if (check_order(stack))
	{
		free_stack(stack);
		exit (1);
	}
	return (1);
}

void	init_tri(t_full_stack *stack)
{
	if (stack_length(stack->a) == 2)
		swap_a(stack, 0);
	else if (stack_length(stack->a) == 3)
		sort_3(stack);
	else
		algo(stack);
}

int	main(int argc, char **argv)
{
	t_full_stack	*stack;

	if (argc <= 1)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!verif(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack = init_lst(argc, argv);
	post_init_check(stack);
	init_tri(stack);
	free_stack(stack);
	return (0);
}
