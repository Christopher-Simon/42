/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/13 00:50:11 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char 	*str;
	size_t	i;


	va_start(args, s);
	i = 0;
	while (*s)
		ft_putchar_fd(*s++, 1);

		
	str = (char *)va_arg(args, char *);

	ft_putstr_fd(str, 1);

	va_end(args);
}
