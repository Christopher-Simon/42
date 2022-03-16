/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/16 14:23:15 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

char *s_fillis(t_flags *flag, int x, char *r, char *str)
{
	ft_memset(r, ' ', x);
	if (flag->prec < flag->size)
		flag->size = flag->prec;
	if (flag->minus)
	{
		ft_strlcpy(r, str, flag->size + 1);
		ft_memset(&r[flag->size],' ', x);
		r[x] = '\0';
	}
	else
		ft_strlcpy(&r[x - flag->size], str, flag->size + 1);
	return(r);
}

int flag_s(t_flags flag, int x, const char *s, char *str)
{
	char *r;

	x = ft_strlen(str);
	flag.size = x;
	if (ft_strchr(s, '-'))
		flag.minus = 1;
	if (find_prec(&flag, s) < x)
		x = flag.prec;
	if (x < find_width(&flag, s))
		x = find_width(&flag, s);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	s_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	x = ft_strlen(r);
	free(r);
	return (x);
}