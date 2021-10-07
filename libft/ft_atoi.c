/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:50:12 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/07 12:29:18 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	a;
	int	i;
	int	neg;

	i = 0;
	a = 0;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else
		neg = 1;
	while (nptr[i])
	{
		a = a * 10 + (nptr[i] - 48);
		i++;
	}
	a *= neg;
	return (a);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("gros boulet");
		return(0);
	}
	printf("%d\n", atoi(av[1]));
	printf("%d\n", ft_atoi(av[1]));
}*/
