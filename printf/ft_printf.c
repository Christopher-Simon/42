/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/02 11:58:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int flag_first(char c)
{
	if (c == '-' || c == '+' || c == ' ' 
		|| c == '0' || c == '#')
		return (1);
	if (c == 'c' || c == 's' || c == 'p' 
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X')
		return (1);
	return(0);
}

int check_flags(char *s)
{
	int i;
	i = 1;
	if (!ft_strchr(s, 'c') && !ft_strchr(s, 's') &&
		!ft_strchr(s, 'p') && !ft_strchr(s, 'd') &&
		!ft_strchr(s, 'i') && !ft_strchr(s, 'u') &&
		!ft_strchr(s, 'x') && !ft_strchr(s, 'X'))
		return (0);
	while (s[i] && !ft_isdigit(s[i]) && s[i] != '.')
	{
		if (!flag_first(s[i]))
			return (i);
		i++;
	}
	while(!ft_isalpha(s[i]) && s[i])
	{
		// printf("is digit ? : %d\n", ft_isdigit(s[i]));
		if (!ft_isdigit(s[i]) && s[i] != '.')
			return(i);
		i++;
	}
	return (0);
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

int put_flag(char *s)
{
	char str[5] = "     ";
	int i;
	int	x;

	i = 1;
	x = 1;
	ft_putchar_fd('%', 1);
	while (s[i] && !ft_isdigit(s[i]) && flag_first(s[i]))
	{
		if (s[i] == '+' && str[0] == ' ')
		{
			str[0]= '+';
			ft_putchar_fd(s[i], 1);
			x++;
		}
		if (s[i] == '-' && str[1] == ' ')
		{
			str[1]= '-';
			ft_putchar_fd(s[i], 1);
			x++;
		}
		if (s[i] == ' ' && str[2] == ' ')
		{
			str[2]= ' ';
			ft_putchar_fd(s[i], 1);
			x++;
		}
		if (s[i] == '#' && str[3] == ' ')
		{
			str[3]= '#';
			ft_putchar_fd(s[i], 1);
			x++;
		}
		if (s[i] == '0' && str[4] == ' ')
		{
			str[4]= '0';
			ft_putchar_fd(s[i], 1);
			x++;
		}
		i++;
	}
	ft_putstr_fd(&s[i], 1);
	x += ft_strlen(&s[i]);
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
		if (!check_flags(s_flag))
			x += argument(s_flag, flag, args);
		else
			x += put_flag(s_flag);
		x--;
		free(s_flag);
	}
	i++;
	x++;
	}
	
	va_end(args);
	return (x);
}
