/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:57 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/31 15:01:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stddef.h>

int	free_gnl(char *instructions)
{
	free(instructions);
	get_next_line(-1);
	return (0);
}

int	get_instructions(char *instructions, t_full_stack *stack)
{
	if (!ft_strncmp(instructions, "sa\n", ft_strlen(instructions)))
	{
		ft_printf("yes");
		swap_a(stack, 0);
	}
	else if (!ft_strncmp(instructions, "sb\n", ft_strlen(instructions)))
		swap_b(stack, 0);
	else if (!ft_strncmp(instructions, "pa\n", ft_strlen(instructions)))
		push_a(stack, 0);
	else if (!ft_strncmp(instructions, "pb\n", ft_strlen(instructions)))
		push_b(stack, 0);
	else if (!ft_strncmp(instructions, "ra\n", ft_strlen(instructions)))
		rotate_a(stack, 0);
	else if (!ft_strncmp(instructions, "rb\n", ft_strlen(instructions)))
		rotate_b(stack, 0);
	else if (!ft_strncmp(instructions, "rr\n", ft_strlen(instructions)))
	{
		rotate_a(stack, 0);
		rotate_b(stack, 0);
	}	
	else if (!ft_strncmp(instructions, "rra\n", ft_strlen(instructions)))
		reverse_rotate_a(stack, 0);
	else if (!ft_strncmp(instructions, "rrb\n", ft_strlen(instructions)))
		reverse_rotate_b(stack, 0);
	else if (!ft_strncmp(instructions, "rrr\n", ft_strlen(instructions)))
	{
		reverse_rotate_a(stack, 0);
		reverse_rotate_b(stack, 0);
	}
	else
	{
		ft_printf("Error\n");
		free_gnl(instructions);
		free_stack(stack);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char			*instructions;
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
	print_stack(stack);
	if (!check_double(stack))
	{
		ft_printf("Error\n");
		return (0);
	}
	print_stack(stack);
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
	print_stack(stack);
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
