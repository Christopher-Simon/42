/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:23:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/31 18:51:10 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

char *s_fillis(t_flags *flag, int x, char *r, char *str)
{
	printf(" x : %d\n size : %d\n width : %d\n prec : %d\n\n", x, flag->size, flag->width, flag->prec);
	ft_memset(r, ' ', x);
	if (!flag->minus)
		ft_strlcpy(&r[x - flag->size], str, flag->size + 1);
	else 
		ft_strlcpy(r, str, flag->size + 1);
	return(r);
}

int flag_s(t_flags flag, int x, const char *s, char *str)
{
	char *r;

	get_flags(&flag, s);
	if ((int)ft_strlen(str) >= flag.prec)
		str = ft_substr(str, 0, flag.prec_size);
	x = ft_strlen(str);
	flag.size = x;
	if (x < flag.width)
		x = flag.width;
	r = malloc(sizeof(char) * (x + 1));
	if (!r)
		return (0);
	s_fillis(&flag, x, r, str);
	printf("taille r : %ld/n", ft_strlen(r));
	ft_putstr_fd(r, 1);
	free(r);
	if (flag.prec && (flag.size == flag.prec_size))
		free(str);
	return (x);
}