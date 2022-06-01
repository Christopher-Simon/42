/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:40:13 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/01 15:06:44 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	check_base(char *base)
{
	unsigned int	a;
	unsigned int	i;

	i = 0;
	while (base[i])
	{
		a = i;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (*(base + ++a))
		{
			if (base[i] == base[a])
			{
				return (0);
			}
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	div;
	unsigned int	mod;
	unsigned int	n;
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (check_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -nbr;
	}
	else
		n = nbr;
	div = n / i;
	mod = n % i;
	if (div != 0)
		ft_putnbr_base(div, base);
	write(1, &base[mod], 1);
}
