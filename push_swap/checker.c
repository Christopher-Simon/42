/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:57 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 17:38:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stddef.h>

void	get_instructions(char *instructions, t_full_stack *stack)
{
	if (!ft_strncmp(instructions, "sa\n", ft_strlen(instructions)))
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
	{
		rotate_a(stack, 1);
		rotate_b(stack, 1);
	}	
	else if (!ft_strncmp(instructions, "rra\n", ft_strlen(instructions)))
		reverse_rotate_a(stack, 1);
	else if (!ft_strncmp(instructions, "rrb\n", ft_strlen(instructions)))
		reverse_rotate_b(stack, 1);
	else if (!ft_strncmp(instructions, "rrr\n", ft_strlen(instructions)))
	{
		reverse_rotate_a(stack, 1);
		reverse_rotate_b(stack, 1);
	}
	else
	{
		ft_printf("Error\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	char			*instructions;
	t_full_stack	*stack;
	int				i;

	i = 0;
	if (argc == 1)
		return (0);
	if (!verif(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack = malloc(sizeof(t_full_stack));
	if (!stack)
		return (0);
	ft_begin(stack, ft_atol(argv[++i], stack));
	while (i++ < argc - 1)
		ft_stack_new(stack, ft_atol(argv[i], stack));
	if (!check_double(stack))
	{
		ft_printf("Error\n");
		return (0);
	}
	instructions = get_next_line(0);
	if (!instructions)
		return (0);
	get_instructions(instructions, stack);
	while (instructions)
	{
		free(instructions);
		instructions = get_next_line(0);
		if (!instructions)
			break ;
		get_instructions(instructions, stack);
	}
	if (check_order(stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}
