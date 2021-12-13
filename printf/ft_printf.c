/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
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
	va_end(args);
	return (i);
}
