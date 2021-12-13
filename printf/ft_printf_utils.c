/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:05:24 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/13 13:17:27 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_int_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_int_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	write(fd, s, ft_strlen(s));
	return ((int)ft_strlen(s));
}

int	ft_int_putnbr_fd(int n, int fd, int	i)
{
	unsigned int	a;

	if (n < 0)
	{
		i += ft_int_putchar_fd('-', fd);
		a = n * (-1);
	}
	else
		a = n;
	if (a / 10 != 0)
		i = ft_int_putnbr_fd(a / 10, fd, i);
	ft_int_putchar_fd(a % 10 + '0', fd);
	return (++i);
}
