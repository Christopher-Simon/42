/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/05 15:03:24 by chsimon          ###   ########.fr       */
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
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	if (!flag.null)
		s_fillis(&flag, x, r, str);
	else 
		s_fillis(&flag, x, r, "(null)");
	ft_putstr_fd(r, 1);
	free(r);
	if (flag.prec && (flag.size == flag.prec_size))
		free(str);
	return (x);
}
