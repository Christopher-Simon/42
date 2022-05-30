/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:58:02 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 18:17:44 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check_double_2(t_stack *stack, int index, int value)
{
	t_stack	*ptr;
	int		index_2;

	ptr = stack;
	index_2 = 1;
	if (value == ptr->value && index != index_2)
	{
		return (0);
	}
	ptr = ptr->next;
	index_2++;
	while (ptr->begin != 1)
	{
		if (value == ptr->value && index != index_2)
		{
			return (0);
		}
		index_2++;
		ptr = ptr->next;
	}
	return (1);
}

int	check_double(t_full_stack *stack)
{
	t_stack	*ptr;
	int		index;

	index = 1;
	ptr = stack->a;
	if (!check_double_2(stack->a, index, ptr->value))
	{
		free_stack(stack);
		return (0);
	}
	index++;
	ptr = ptr->next;
	while (ptr->begin != 1)
	{
		if (!check_double_2(stack->a, index, ptr->value))
		{
			free_stack(stack);
			return (0);
		}
		index++;
		ptr = ptr->next;
	}
	return (1);
}

int	is_valid(int c, int i)
{
	if (!ft_isdigit(c))
	{
		if (i == 0)
		{
			if (c == '-')
				return (1);
			else if (c == '+')
				return (1);
		}
		return (0);
	}
	return (1);
}

int	verif_arg(char *arg)
{
	int	i;

	i = 0;
	if (!ft_strlen(arg))
		return (0);
	if (arg[0] == '-' && !arg[1])
		return (0);
	if (arg[0] == '+' && !arg[1])
		return (0);
	while (arg[i])
	{	
		if (!is_valid(arg[i], i))
			return (0);
		i++;
	}
	return (1);
}

int	verif(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!verif_arg(argv[i]))
			return (0);
		i++;
	}
	i = 1;
	return (1);
}
