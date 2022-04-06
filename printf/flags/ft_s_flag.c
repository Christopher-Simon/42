/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/06 14:55:49 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

char	*s_fillis(t_flags *flag, int x, char *r, char *str)
{
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - flag->size], str, flag->size);
	else
		ft_strcpy(r, str, flag->size);
	return (r);
}

char	*flag_s_null(t_flags *flag, int *y, char *r, char *str)
{

	if (!flag->width &&flag->prec && flag->prec_size < 6)
	{
		*y = 0;
	}
	else if (flag->prec && flag->width)
	{
		*y = flag->width;
	}
	r = malloc(sizeof(char) * (*y + 1));
	if (!r)
		return (0);
	s_fillis(flag, *y, r, str);
	return (r);
}

int	flag_s(t_flags flag, int x, char *s, char *str)
{
	char	*r;

	get_flags(&flag, s);
	if (!str)
	{
		flag.null = 1;
		x = 6;
	}
	else 
	{
		if (flag.prec && ((int)ft_strlen(str) >= flag.prec_size))
			str = ft_substr(str, 0, flag.prec_size);
		x = ft_strlen(str);
	}
	flag.size = x;
	if (x < flag.width)
		x = flag.width;
	if (flag.null)
	{
		flag_s_null(&flag, &x, r, "(null)");
		return (x);
	}
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	s_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	if (flag.prec && (flag.size == flag.prec_size))
		free(str);
	return (x);
}
