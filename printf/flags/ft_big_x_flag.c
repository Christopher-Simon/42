/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_x_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:26 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/02 17:16:08 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

int	flag_big_x(t_flags flag, int x, char *s, long int i)
{
	char	*r;
	char	*str;

	get_flags(&flag, s);
	str = ft_convert_base(ft_itoa(i), "0123456789", "0123456789ABCDEF");
	x = ft_strlen(str);
	flag.size = x;
	if (x < flag.prec)
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