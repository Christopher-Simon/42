/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:57 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 16:20:22 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stddef.h>

int	wrong_param(char *instructions, t_full_stack *stack)
{
	ft_printf("Error\n");
	free_stack(stack);
	free(instructions);
	get_next_line(-1);
	return (0);
}

int	get_instructions(char *instructions, t_full_stack *stack)
{
	if (ft_strlen(instructions) == 0)
		return (1);
	else if (!ft_strncmp(instructions, "sa\n", ft_strlen(instructions)))
		swap_a(stack, 1);
	else if (!ft_strncmp(instructions, "sb\n", ft_strlen(instructions)))
		swap_b(stack, 1);
	else if (!ft_strncmp(instructions, "pa\n", ft_strlen(instructions)))
		push_a(stack, 1);
	else if (!ft_strncmp(instructions, "pb\n", ft_strlen(instructions)))
		push_b(stack, 1);
	else if (!ft_strncmp(instructions, "ra\n", ft_strlen(instructions)))
		rotate_a(stack, 1);
	else if (!ft_strncmp(instructions, "rb\n", ft_strlen(instructions)))
		rotate_b(stack, 1);
	else if (!ft_strncmp(instructions, "rr\n", ft_strlen(instructions)))
		rr(stack, 1);
	else if (!ft_strncmp(instructions, "rra\n", ft_strlen(instructions)))
		reverse_rotate_a(stack, 1);
	else if (!ft_strncmp(instructions, "rrb\n", ft_strlen(instructions)))
		reverse_rotate_b(stack, 1);
	else if (!ft_strncmp(instructions, "rrr\n", ft_strlen(instructions)))
		rrr(stack, 1);
	else
		return (wrong_param(instructions, stack));
	return (1);
}

int	read_instructions(t_full_stack *stack)
{
	char			*instructions;

	instructions = get_next_line(0);
	if (!get_instructions(instructions, stack))
		return (0);
	while (instructions)
	{
		free(instructions);
		instructions = get_next_line(0);
		if (!instructions)
			break ;
		if (!get_instructions(instructions, stack))
			return (0);
	}
	return (1);
}

int	check_stack(t_full_stack *stack)
{
	if (stack->b)
	{
		free_stack(stack);
		ft_printf("KO\n");
		return (0);
	}
	if (check_order(stack))
	{
		ft_printf("OK\n");
		free_stack(stack);
		return (1);
	}
	else
	{
		ft_printf("KO\n");
		free_stack(stack);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_full_stack	*stack;

	if (argc == 1)
		return (0);
	if (!verif(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack = init_lst(argc, argv);
	if (!stack)
		return (0);
	if (!check_double(stack))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!read_instructions(stack))
		return (0);
	return (check_stack(stack));
}