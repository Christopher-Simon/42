/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/31 15:38:13 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags flag;
	int x;

	va_start(args, s);
	if (ft_strchr(s, 'c'))
		x = flag_c(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 's'))
		x = flag_s(flag, 0, s, va_arg(args, char *));
	if (ft_strchr(s, 'p'))
		x = flag_p(flag, 0, s, va_arg(args, unsigned long));
	if (ft_strchr(s, 'd'))
		x = flag_d(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 'i'))
		x = flag_i(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 'u'))
		x = flag_u(flag, 0, s, va_arg(args, int));
	if (ft_strchr(s, 'x'))
		x = flag_x(flag, 0, s, va_arg(args, long int));
	if (ft_strchr(s, 'X'))
		x = flag_big_x(flag, 0, s, va_arg(args, int));
	va_end(args);
	return (x);
}
