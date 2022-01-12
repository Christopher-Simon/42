/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:29:08 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/12 18:34:39 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int	find_nb_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

int	find_prec(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			return (ft_atoi(&s[i + 1]));
		i++;
	}
	return (0);
}

int	find_width(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			return (ft_atoi(&s[i]));
		i++;
	}
	return (0);
}

int	max_size(int w, int p, int n)
{
	if (w > p)
	{
		if (w > n)
			return (w);
	}
	if (p > w)
	{
		if (p > n)
			return (p);
	}
	return (n);
}
