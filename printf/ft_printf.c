/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
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
=======
/*   Created: 2021/12/13 11:15:13 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/13 16:25:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list args;
	int		i;
	
	i = 0;
	va_start(args, s);
	while (s[i] && s[i] != '%' )
		i += ft_int_putchar_fd(s[i], 1);
	i += ft_int_putstr_fd(va_arg(args, char *), 1);
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016
	va_end(args);
	return (i);
}
