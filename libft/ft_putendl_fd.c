/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:44:20 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/24 18:21:55 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_strlen(char *str);

void 	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(1, "\n", 1);
}
/*
int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ft_putendl_fd(av[1], 1);
}*/
