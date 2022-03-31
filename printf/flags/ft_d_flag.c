/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:24:59 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/31 04:30:52 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

static void prec(t_flags *flag, int x, char *r)
{
	int i;

	if (flag->minus)
		i = x;
	else 
		i = flag->prec;
	if (flag->minus && (flag->space || flag->plus))
		i--;
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

static void plus(int x, char *r)
{
	x++;
	while (x--)
	{
		if (r[x] == ' ')
		{
			r[x] = '+';
			break;
		}
	}
}

static void neg(int x, char *r)
{
	while (x--)
	{
		if (r[x] == ' ')
		{
			r[x] = '-';
			break;
		}
	}
}

static void zero(t_flags *flag, int x, char *r)
{
	int i;

	i = flag->width;
	if (flag->neg || flag->plus || flag->space)
		i--;
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

void d_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if ((flag->minus && (flag->space || flag->plus)) || flag->neg)
		x++;
	ft_strlcpy(&r[x - flag->size], str, flag->size + 1);
	if (flag->neg)
		r[0]='-';
	if (flag->plus && !flag->neg)
		r[0]='+';
}

char	*d_fillis(t_flags *flag, int x, char *r, char *str)
{
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	if (!flag->minus)
		ft_strlcpy(&r[x - (flag->size) - flag->minus], str, flag->size + 1);
	else 
		d_minus(flag, x, r ,str);
	if (flag->prec)
		prec(flag, x, r);
	if (flag->neg)
		neg(x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	if (flag->plus && !flag->neg)
		plus(x, r);
	free(str);
	return (r);
}

char *get_d(t_flags *flag, int d)
{
	char *str;
	char *r;
	
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

int flag_d(t_flags flag, int x, const char *s, int d)
{
	char *r;
	char *str;

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
		return(0);
	d_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}