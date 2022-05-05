/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_x_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:26 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/05 16:15:40 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

char	*flag_big_x_null(int x)
{
	char	*str;

	str = malloc(x + 1);
	if (!str)
		return (0);
	if (!x)
		str[0] = '\0';
	else
		ft_strlcpy(str, " ", 2);
	return (str);
}

int	flag_big_x(t_flags flag, int x, char *s, long int i)
{
	char	*r;
	char	*str;

	get_flags(&flag, s);
	if (!i && flag.prec_size == 0)
		flag.null = 1;
	if (flag.null && flag.prec && flag.prec_size == 0)
		str = flag_big_x_null(flag.prec_size);
	else
		str = ft_convert_base(ft_itoa(i), "0123456789", "0123456789ABCDEF");
	x = ft_strlen(str);
	flag.size = x;
	if (x < flag.prec && !flag.null)
		x = flag.prec;
	if (flag.hash && i != 0)
		x += 2;
	else
		flag.hash = 0;
	if (x < flag.width)
		x = flag.width;
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	big_x_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
