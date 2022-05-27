/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:42:19 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/27 18:35:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long int	ft_atol(const char *nptr, t_full_stack *stack)
{
	long int	a;
	int			i;
	int			neg;

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
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		a = a * 10 + (nptr[i] - 48);
		i++;
	}
	a *= neg;
	if (a > 214748364 || a < -2147483648)
	{
		if (stack)
			free_stack(stack);
		exit(1);
	}
	printf("%ld\n", a);
	return (a);
}
