/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:59:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/01 01:59:42 by chsimon          ###   ########.fr       */
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
	// if (flag->minus && (flag->space || flag->plus))
	// 	i--;
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

static void zero(t_flags *flag, int x, char *r)
{
	int i;

	i = flag->width;
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

void u_minus(t_flags *flag, int x, char *r, char *str)
{
	x = flag->size;
	if (flag->prec > flag->size)
		x = flag->prec;
	// if ((flag->minus && (flag->space || flag->plus)) || flag->neg)
	// 	x++;
	ft_strcpy(&r[x - flag->size], str, flag->size);
	// if (flag->neg)
	// 	r[0]='-';
	// if (flag->plus && !flag->neg)
	// 	r[0]='+';
}

char	*u_fillis(t_flags *flag, int x, char *r, char *str)
{
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	if (!flag->minus)
		ft_strcpy(&r[x - (flag->size) - flag->minus], str, flag->size);
	else 
		u_minus(flag, x, r ,str);
	if (flag->prec)
		prec(flag, x, r);
	// if (flag->neg)
	// 	neg(x, r);
	if (flag->zero && !flag->prec && !flag->minus)
		zero(flag, x, r);
	// if (flag->plus && !flag->neg)
	// 	plus(x, r);
	free(str);
	return (r);
}

char *get_u(t_flags *flag, unsigned int d)
{
	char *str;
	(void)flag;
	
	str = ft_itoa_long(d);
	return (str);
}

int flag_u(t_flags flag, int x, const char *s, int d)
{
	unsigned int i;
	char *r;
	char *str;

	get_flags(&flag, s);
	if (d < 0)
		i = 4294967296 + d;
	else 
		i = d;
	x = find_nb_size(&flag, i);
	flag.size = x;
	if (x < flag.prec)
		x = flag.prec;
	if (x < flag.width)
		x = flag.width;
	str = get_u(&flag, i);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return(0);
	u_fillis(&flag, x, r, str);
	printf("taille r : %ld\n", ft_strlen(r));
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}