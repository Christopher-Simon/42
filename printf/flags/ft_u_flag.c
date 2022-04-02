/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 02:59:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/04/02 17:21:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../printf.h"

char	*get_u(t_flags *flag, unsigned int d)
{
	char	*str;

	(void)flag;
	str = ft_itoa_long(d);
	return (str);
}

int	flag_u(t_flags flag, int x, char *s, int d)
{
	unsigned int	i;
	char			*r;
	char			*str;

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
		return (0);
	u_fillis(&flag, x, r, str);
	ft_putstr_fd(r, 1);
	free(r);
	return (x);
}
