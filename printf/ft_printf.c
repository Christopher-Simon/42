/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:02:15 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/12 19:18:20 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

char	*str_fill(char *str, int n, int nb, int d)
{
	while (nb-- >= 0)
	{
		str[n - nb] = d % 10;
		d /= 10;
	}
	return (str);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	char *str;
	t_flags flag;

	va_start(args, s);
	flag.width = find_width(s);
	flag.prec = find_prec(s);
	flag.nb_size = find_nb_size(va_arg(args, int));
	flag.size = max_size(flag.width, flag.prec, flag.nb_size);
	str = malloc(sizeof(char)*(flag.size + 1));
	if (!str)
		return (0);
	ft_memset(str, ' ', max_size(flag.width, flag.prec, flag.nb_size));
	printf("%s|\n",str);
	str_fill(str, flag.size, flag.nb_size, va_arg(args, int));
	printf("%s|\n",str);
	va_end(args);
	free (str);
	return (1);
}
