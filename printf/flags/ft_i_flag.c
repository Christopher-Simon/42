/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:08:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/01 02:31:39 by chsimon          ###   ########.fr       */
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
	x--;
	i--;
	while(r[x] == ' ')
	{
		x--;
		i--;
	}
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

static void plus(int x, char *r)
{
	x--;
	while(r[x] == ' ')
		x--;
	while (x >= 0)
	{
		if (r[x] == ' ')
		{
			r[x] = '+';
			break;
		}
		x--;
	}
}

static void neg(int x, char *r)
{
	x--;
	while(r[x] == ' ')
		x--;
	while (x >= 0)
	{
		if (r[x] == ' ')
		{
			r[x] = '-';
			break;
		}
		x--;
	}
}

static void zero(t_flags *flag, int x, char *r)
{
	int i;

	i = flag->width;
	if (flag->neg || flag->plus || flag->space)
		i--;
	while(r[x] == ' ')
		x--;
	while (x >= 0 && i >= 0)
	{
		if (r[x] == ' ')
			r[x] = '0';
		x--;
		i--;
	}
}

void i_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if ((flag->minus && (flag->space || flag->plus)) || flag->neg)
		x++;
	ft_strcpy(&r[x - flag->size], str, flag->size);
	// if (flag->neg)
	// 	r[0]='-';
	// if (flag->plus && !flag->neg)
	// 	r[0]='+';
}

char	*i_fillis(t_flags *flag, int x, char *r, char *str)
{
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - (flag->size) - flag->minus], str, flag->size);
	else 
		i_minus(flag, x, r ,str);
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

char *get_i(t_flags *flag, int i)
{
	char *str;
	char *r;
	
	str = ft_itoa(i);
	if (flag->neg)
	{
		r = ft_substr(str, 1, flag->size);
		free(str);
	}
	else 
		r = str;
	return (r);
}

int flag_i(t_flags flag, int x, const char *s, int i)
{
	char *r;
	char *str;

	get_flags(&flag, s);
	x = find_nb_size(&flag, i);
	flag.size = x - flag.neg; 
	if (x < flag.prec)
		x = flag.prec + flag.neg;
	if (x < flag.width)
		x = flag.width;
	if ((flag.space || flag.plus) && (x == flag.size || x == flag.prec))
		x += 1 - flag.neg;
	str = get_i(&flag, i);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return(0);
	i_fillis(&flag, x, r, str);
	printf("taille r : %ld\n", ft_strlen(r));
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}