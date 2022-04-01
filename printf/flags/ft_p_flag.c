/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:56 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/01 23:39:50 by chsimon          ###   ########.fr       */
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
	if (flag->minus && (flag->plus || flag->space))
		i -= 1;
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

static void zero(t_flags *flag, int x, char *r)
{
	int i;

	i = flag->width - 1;
	if (flag->plus || flag->space)
		i--;
	while(r[x] == ' ')
		x--;
	while (x >= 0 && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
		x--;
	}
}

static void hash(t_flags *flag, int x, char *r)
{
	if (flag->minus)
		x = flag->size;
	while (x >= 0)
	{
		if (r[x] == ' ')
		{
			r[x] = 'x';
			r[x - 1] = '0';
			break;
		}
		x--;
	}
}

void p_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	if (flag->minus && (flag->space || flag->plus))
		x++;
	if (flag->hash)
		x += 2;
	ft_strcpy(&r[x - flag->size], str, flag->size);
	// if (flag->neg)
	// // 	r[0]='-';
	// if (flag->plus && !flag->neg)
	// 	r[0]='+';
}

char	*p_fillis(t_flags *flag, int x, char *r, char *str)
{
	// printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	r[x] = '\0';
	if (!flag->minus)
		ft_strcpy(&r[x - (flag->size) - flag->minus], str, flag->size);
	else 
		p_minus(flag, x, r ,str);
	if (flag->prec)
		prec(flag, x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	if (flag->hash)
		hash(flag, x, r);
	if (flag->plus && !flag->neg)
		plus(x, r);
	free(str);
	return (r);
}

int flag_p(t_flags flag, int x, char *s, unsigned long i)
{
	char *str;
	char *r;

	get_flags(&flag, s);
	str = ft_dec_to_hex((unsigned long) i);
	x = ft_strlen(str) + 2;
	flag.size = x - 2;
	flag.hash = 1;
	if (x < flag.prec + 2)
		x = flag.prec + 2;
	if (x < flag.width)
		x = flag.width;
	if ((flag.space || flag.plus) 
		&& (x == (flag.size + 2)|| x == flag.prec + 2))
	{
		printf("yes\n");
		x += 1 - flag.neg;
	}	
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return(0);
	p_fillis(&flag, x, r, str);
	printf("taille r : %ld\n", ft_strlen(r));
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
