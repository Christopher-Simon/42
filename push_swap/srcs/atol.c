/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:42:19 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/30 17:38:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	overflow_check(long int a, t_full_stack *stack)
{
	if (a < -2147483648 || a > 2147483647)
	{
		if (stack->a)
			free_stack(stack);
		else
			free(stack);
		ft_printf("Error\n");
		exit(1);
	}
	return (0);
}

int	long_check(const char *nptr, t_full_stack *stack)
{
	if (ft_strlen(nptr) > 12)
	{
		if (stack->a)
			free_stack(stack);
		else
			free(stack);
		ft_printf("Error\n");
		exit(1);
	}
	return (0);
}

long int	atol_while(const char *nptr, int i, long int a)
{
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		a = a * 10 + (nptr[i] - 48);
		i++;
	}
	return (a);
}

long int	ft_atol(const char *nptr, t_full_stack *stack)
{
	long int	a;
	int			i;
	int			neg;

	while (*nptr == '0' && nptr[1] != '\0')
		nptr++;
	long_check(nptr, stack);
	i = 0;
	a = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	a = atol_while(nptr, i, a);
	a *= neg;
	overflow_check(a, stack);
	return (a);
}
