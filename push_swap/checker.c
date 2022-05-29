/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:57 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/29 12:58:55 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned long int	i;

    i = 0;
    if (n == 0)
		return (0);
    if (!s1[i])
		return (s1[i] - s2[i]);
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
    unsigned long int	i;

	i = 0;
	if (!s1[i])
		return (s1[i] - s2[i]);
	while (s1[i])
	{
		printf("%d | %d\n", s1[i], s2[i]);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


void	get_instructions(char *instructions, t_full_stack *stack)
{
	if(!ft_strncmp(instructions, "sa\n", ft_strlen(instructions)))
		s_swap_a(stack);
	if(!ft_strncmp(instructions, "sb\n", ft_strlen(instructions)))
		s_swap_b(stack);
	if(!ft_strncmp(instructions, "pa\n", ft_strlen(instructions)))
		s_push_a(stack);
	if(!ft_strncmp(instructions, "pb\n", ft_strlen(instructions)))
		s_push_b(stack);
	if(!ft_strncmp(instructions, "ra\n", ft_strlen(instructions)))
		s_rotate_a(stack);
	if(!ft_strncmp(instructions, "rb\n", ft_strlen(instructions)))
		s_rotate_b(stack);	
	if(!ft_strncmp(instructions, "rr\n", ft_strlen(instructions)))
	{
		s_rotate_a(stack);
		s_rotate_b(stack);
	}	
	if(!ft_strncmp(instructions, "rra\n", ft_strlen(instructions)))
		s_reverse_rotate_a(stack);
	if(!ft_strncmp(instructions, "rrb\n", ft_strlen(instructions)))
		s_reverse_rotate_b(stack);
	if(!ft_strncmp(instructions, "rrr\n", ft_strlen(instructions)))
	{
		s_reverse_rotate_a(stack);
		s_reverse_rotate_b(stack);
	}
}

// Ajouter error pour mauvaises instructions

int	main(int argc, char **argv)
{
	char	*instructions;
	t_full_stack	*stack;

	int				i;

	i = 0;
	if (!verif(argv))
	{
		printf("Error\n");
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
		printf("Error\n");
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
		// printf("%s", instructions);
		get_instructions(instructions, stack);
	}
	if (check_order(stack))
		printf("OK\n");
	else
		printf("KO\n");
	return (1);
}