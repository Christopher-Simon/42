/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/16 14:31:30 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"


int flag_i(t_flags flag, int x, const char *s, int i)
{
	x = find_nb_size(&flag, i);
	if (x < find_width(&flag, s))
		x = find_width(&flag, s);
	if (x < find_prec(&flag, s))
		x = find_prec(&flag, s);
	if (ft_strchr(s, '+') && (x == flag.size || x <= find_prec(&flag, s)))
		x++;
	if (flag.neg && x == find_prec(&flag, s))
		x++;
	return (x);
}

int flag_u(t_flags flag, int x, const char *s, int d)
{
	unsigned int i;

	if (d < 0)
		i = 4294967296 + d;
	else 
		i = d;
	x = find_nb_size(&flag, i);
	if (x < find_width(&flag, s))
		x = find_width(&flag, s);
	if (x < find_prec(&flag, s))
		x = find_prec(&flag, s);
	return (x);
}

int flag_x(t_flags flag, int x, const char *s, long int i)
{
	(void) flag;
	(void) s;

	char *r = ft_convert_base(ft_itoa(i), "0123456789", "0123456789abcdef");
	x = ft_strlen(r);
	if (x < find_prec(&flag, s))
		x = find_prec(&flag, s);
	if (ft_strchr(s, '#'))
		x += 2;
	if (x < find_width(&flag, s))
		x = find_width(&flag, s);
	if (flag.neg && x == find_prec(&flag, s))
		x++;
	free(r);
	return (x);
}

int flag_big_x(t_flags flag, int x, const char *s, int i)
{
	(void) flag;
	(void) s;

	char *r = ft_convert_base(ft_itoa(i), "0123456789", "0123456789abcdef");
	x = ft_strlen(r);
	if (x < find_prec(&flag, s))
		x = find_prec(&flag, s);
	if (ft_strchr(s, '#'))
		x += 2;
	if (x < find_width(&flag, s))
		x = find_width(&flag, s);
	if (flag.neg && x == find_prec(&flag, s))
		x++;
	free(r);
	return (x);
}

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
