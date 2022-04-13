/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:56 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/11 20:44:36 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

void	p_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if (flag->minus && (flag->space || flag->plus))
		x++;
	if (flag->hash)
		x += 2;
	ft_strcpy(&r[x - flag->size], str, flag->size);
}

char	*flag_p_null(int x)
{
	char	*str;

	str = malloc(sizeof(char)* (x+1));
	if (!str)
		return (0);	
	ft_strlcpy(str, "(nil)", 6);
	return (str);
}

int	flag_p(t_flags flag, int x, char *s, unsigned long i)
{
	char	*str;
	char	*r;

	get_flags(&flag, s);
	if (!i)
		flag.null = 1;
	if (!flag.null)
	{
		str = ft_dec_to_hex((unsigned long) i);
		x = ft_strlen(str) + 2;
		flag.size = x - 2;
		flag.hash = 1;
		if (x < flag.prec + 2)
			x = flag.prec + 2;
		if (x < flag.width)
			x = flag.width;
		if ((flag.space || flag.plus)
			&& (x == (flag.size + 2) || x == flag.prec + 2))
			x += 1 - flag.neg;	
	}
	else 
	{
		str = flag_p_null(5);
		x = ft_strlen(str);
		flag.size = x;
		if (x < flag.width)
			x = flag.width;
	}
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	p_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
