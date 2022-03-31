/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_x_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:26 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/31 15:39:46 by chsimon          ###   ########.fr       */
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
	if (flag->minus && (flag->hash))
		i -= 2;
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

static void zero(t_flags *flag, int x, char *r)
{
	int i;

	i = flag->width;
	// if (flag->neg || flag->plus || flag->space)
	// 	i--;
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

static void hash(t_flags *flag, int x, char *r)
{
	(void)flag;
	if (flag->minus)
		x = flag->size;
	while (x--)
	{
		if (r[x] == ' ')
		{
			r[x] = 'X';
			r[x - 1] = '0';
			break;
		}
	}
}

static void x_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if (flag->hash)
		x += 2;
	ft_strlcpy(&r[x - flag->size], str, flag->size + 1);
	// if (flag->neg)
	// 	r[0]='-';
	// if (flag->plus && !flag->neg)
	// 	r[0]='+';
}

static char	*x_fillis(t_flags *flag, int x, char *r, char *str)
{
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	if (!flag->minus)
		ft_strlcpy(&r[x - (flag->size) - flag->minus], str, flag->size + 1);
	else 
		x_minus(flag, x, r ,str);
	if (flag->prec)
		prec(flag, x, r);
	if (flag->hash)
		hash(flag, x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	// if (flag->plus && !flag->neg)
	// 	plus(x, r);
	free(str);
	return (r);
}

int flag_big_x(t_flags flag, int x, const char *s, long int i)
{
	char *r;
	char *str;

	get_flags(&flag, s);
	str = ft_convert_base(ft_itoa(i), "0123456789", "0123456789ABCDEF");
	x = ft_strlen(str);
	flag.size = x;
	if (x < find_prec(&flag, s))
		x = find_prec(&flag, s);
	if (flag.hash && i != 0)
		x += 2;
	else
		flag.hash = 0;
	if (x < find_width(&flag, s))
		x = find_width(&flag, s);
	// if (flag.neg && x == find_prec(&flag, s))
	// 	x++;
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return(0);
	x_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}