/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:56 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/16 14:24:21 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

char *p_fillis(t_flags *flag, int x, char *r, char *str)
{
	int push = 0;
	
	if (flag->space || flag->plus)
		push = 1;
	ft_memset(r, ' ', x);
	if (flag->prec + 2 > flag->size)
		ft_strlcpy(&r[x - flag->prec - 2], "0x", 3);
	else
		ft_strlcpy(&r[x - flag->size], "0x", 3);
	if (flag->prec + 2 > flag->size)
		ft_memset(&r[x - flag->prec], '0', (flag->prec + 2 - flag->size));
	ft_strlcpy(&r[x - flag->size + 2], str, flag->size);
	if (flag->space)
		r[0] = ' ';
	if (flag->plus && (flag->prec + 2 > flag->size))
		r[x - flag->prec - 3] = '+';
	else if (flag->plus)
		r[x - flag->size - 1] = '+';
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	if (flag->minus)
	{
		if (flag->plus)
			r[0] = '+';
		ft_strlcpy(&r[push], "0x", 3);
		if (flag->prec > flag->size)
			ft_memset(&r[2 + push], '0', (flag->prec - flag->size + 2));
		else
			flag->prec = flag->size - 2;
		ft_strlcpy(&r[flag->prec - flag->size + 4 + push], str, flag->size - 1);
		ft_memset(&r[flag->prec + 2 + push], ' ', x - flag->prec + 2);
		r[x] = '\0';
	}
	// size > tout : rien
	// w > tout 
	// 		p > size : s'ajuste vers la gauche (0 ou +)
	//		p < size : rien
	// p + 2 > tout 
	// 		size > w : 0x à gauche et 0 entre
	// 		w > size : "

	// if (flag->minus)
	// 	ft_strlcpy(r, str, x + 1);
	// else
	// 	ft_strlcpy(&r[x - flag->size + 2], str, x + 1);
	free(str);
	return (r);
}

int flag_p(t_flags flag, int x, const char *s, unsigned long i)
{
	char *str;
	char *r;

	get_flags(&flag, s);
	str = ft_dec_to_hex((unsigned long) i);
	x = (ft_strlen(str) + 2);
	flag.size = x;
	if (ft_strchr(s, '-'))
		flag.minus = 1;
	if (x - 2 < flag.prec)
		x = (flag.prec + 2);
	if (x < flag.width)
		x = flag.width;
	if (flag.space || flag.plus)
	{
		if ((find_prec(&flag, s) + 2) >= find_width(&flag, s))
			x += 1;
		else if (flag.size >= find_width(&flag, s))
			x += 1;
	}
	if (flag.zero && !flag.prec)
	{
		flag.prec = flag.width - 2;
		flag.width = 0;
	}
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return(0);
	p_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	x = ft_strlen(r);
	free(r);
	return (x);
}
