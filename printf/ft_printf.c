/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/01 23:37:19 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int flag_first(char c)
{
	if (c != '-' || c != '+' || c != ' ' 
		|| c != '0' || c != '#')
		return (0);
	return(1);
}

int check_flags(char *s)
{
	int i;

	printf("\n%s", s);
	i = 0;
	if (!ft_strchr(s, 'c') && !ft_strchr(s, 's') &&
		!ft_strchr(s, 'p') && !ft_strchr(s, 'd') &&
		!ft_strchr(s, 'i') && !ft_strchr(s, 'u') &&
		!ft_strchr(s, 'x') && !ft_strchr(s, 'X'))
		return (0);
	while (s[i] && !ft_isdigit(s[i]))
	{
		// flag_first(s[i++]);
		i++;
	}
	printf("\ni : %d\n", i);
	return (1);
}

int argument(char *s, t_flags flag, va_list args)
{
	int x;

	x = 0;
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
	return (x);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	t_flags flag;
	int x;
	int i;
	int mem;
	char *s_flag;

	va_start(args, s);
	i = 0;
	x = 0;
	mem = 0;
	while (s[i])
	{
	if (s[i] != '%')	
		ft_putchar_fd(s[i], 1);
	else 
	{
		mem = i;
		while (!ft_isalpha(s[i]))
			i++;
		// printf("\ni : %c\n", s[i]);
		s_flag = ft_substr(s, mem, i - mem + 1);
		if (check_flags(s_flag))
			x += argument(s_flag, flag, args);
		else 
		{
			x += ft_strlen(s_flag);
			ft_putstr_fd(s_flag, 1);
		}
		x--;
		free(s_flag);
		// printf("flag.minus : %d\n", flag.minus);
		// printf("flag.neg : %d\n", flag.neg);
		// printf("flag.width : %d\n", flag.width);
		// printf("flag.prec : %d\n", flag.prec);
		// printf("flag.prec_size : %d\n", flag.prec_size);
	}
	i++;
	x++;
	}
	
	va_end(args);
	return (x);
}
