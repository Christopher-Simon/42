/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:24:59 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/16 18:08:41 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

void prec(t_flags *flag, int x, char *r)
{
	int i;

	i = flag->prec;
	while (x-- && i--)
	{
		if (r[x] == ' ')
			r[x] = '0';
	}
}

void plus(t_flags *flag, int x, char *r)
{
	(void)flag;
	while (x--)
	{
		if (r[x] == ' ')
		{
			r[x] = '+';
			break;
		}
	}
} 

char	*d_fillis(t_flags *flag, int x, char *r, char *str)
{
	printf("str: %s\n", str);
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	ft_strlcpy(&r[x - flag->size], &str[flag->neg], flag->size + 1);
	prec(flag, x, r);
	if (flag->plus)
		plus(flag, x, r);
	free(str);
	return (r);
}

/*
Prio flag d : 
prec > 0
+>' '
+&' ' ajoute +1 si prec top
# n'existe pas
*/

int flag_d(t_flags flag, int x, const char *s, int d)
{
	char *r;
	char *str;

	get_flags(&flag, s);
	x = find_nb_size(&flag, d);
	flag.size = x;
	if (flag.width)
		x = flag.width;
	if (x < flag.prec)
		x = flag.prec;
	if (flag.neg)
		flag.size--;
	str = ft_itoa(d);
	printf("str: %s\n", str);
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	r = d_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}