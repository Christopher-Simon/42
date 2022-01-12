/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:51:20 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/12 12:51:27 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	a;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		a = n * (-1);
	}
	else
		a = n;
	if (a / 10 != 0)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd(a % 10 + '0', fd);
}
