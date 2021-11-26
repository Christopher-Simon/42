/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:17:23 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/26 15:11:18 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	int_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;
	int				neg;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		neg = 1;
	}
	else
		neg = 0;
	i = int_size(nb) + neg;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	while (i-- > (0 + neg))
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
/*
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("wrong argument");
		return (0);
	}
	printf("%s\n", ft_itoa(atoi(av[1])));
}*/
