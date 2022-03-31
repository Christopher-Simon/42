/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:19:29 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/31 17:21:28 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

void get_flags(t_flags *flag, const char *s)
{
	flag->minus = 0;
	flag->nb_size = 0;
	flag->neg = 0;
	flag->size = 0;
	flag->width = 0;
	flag->prec = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->hash = 0;

	find_width(flag, s);
	flag->prec_size = find_prec(flag, s);
	find_zero(flag, s);
	if (ft_strchr(s, '-'))
		flag->minus = 1;
	if (ft_strchr(s, ' '))
		flag->space = 1;
	if (ft_strchr(s, '+'))
		flag->plus = 1;
	if (ft_strchr(s, '#'))
		flag->hash = 1;
}