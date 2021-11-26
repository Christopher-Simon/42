/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:50:12 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/26 18:32:20 by chsimon          ###   ########.fr       */
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
	while(nptr[i] == '\t'|| nptr[i] == '\n'||nptr[i] == '\r'||
			nptr[i] == '\v'||nptr[i] == '\f'||nptr[i] == ' ')
		i++;
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
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
#include <string.h>

int	main(void)
{
	const char *str[] = {"0", "1", "5", "-1", "-5", "10", "-10", "-1000", "1000", "-2147483648","2147483647", "-2147483649","2147483648", "-54705", "546", "-4452", "548", "-5246", "5246", "-452", "-253", "00074", "+-54", "546:4", "\t\n\r\v\f  469 \n","\f469",NULL};
	int	i;
//	if (ac != 2)
//	{
//		printf("gros boulet");
//		return(0);
//	}
	i = 0;
	while (str[i])
	{
		printf("------");
		if( atoi(str[i]) == ft_atoi(str[i]))
			printf("OK -> ");
		else
			printf("KO -> ");
		printf("atoi : %d | %d : ft_atoi\n", atoi(str[i]), ft_atoi(str[i]));
	i++;
	}
}*/
