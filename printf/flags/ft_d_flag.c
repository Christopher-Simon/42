/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:24:59 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/02 17:28:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

void	d_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if ((flag->minus && (flag->space || flag->plus)) || flag->neg)
		x++;
	ft_strcpy(&r[x - flag->size], str, flag->size);
}

char	*get_d(t_flags *flag, int d)
{
	char	*str;
	char	*r;

	str = ft_itoa(d);
	if (flag->neg)
	{
		r = ft_substr(str, 1, flag->size);
		free(str);
	}
	else
		r = str;
	return (r);
}

int	flag_d(t_flags flag, int x, char *s, int d)
{
	char	*r;
	char	*str;

	get_flags(&flag, s);
	x = find_nb_size(&flag, d);
	flag.size = x - flag.neg;
	if (x < flag.prec)
		x = flag.prec + flag.neg;
	if (x < flag.width)
		x = flag.width;
	if ((flag.space || flag.plus) && (x == flag.size || x == flag.prec))
		x += 1 - flag.neg;
	str = get_d(&flag, d);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	d_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
