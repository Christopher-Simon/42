/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:52:50 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/04 18:00:56 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("boulet");
		return (0);
	}
	printf("%d" ,ft_strlen(av[1]));
}*/
