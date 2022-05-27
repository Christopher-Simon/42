/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 13:58:02 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/27 16:11:09 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	verif_arg(char *arg)
{
	int	i;

	i = 1;
	if (!ft_strlen(arg))
		return (0);
	if (arg[0] == '-' && !arg[1])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	verif(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!verif_arg(argv[i]))
			return (0);
		i++;
	}
	i = 1;
	return (1);
}
