/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/04 18:09:29 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;

	i = 0;
	va_start(args, s);
	while (s[i] != '%' && s[i])
		i += ft_putchar_fd(s[i], 1);
	ft_putstr	
	va_end(args);
	return (i);
}
