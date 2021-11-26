/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:15:29 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/26 16:02:13 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = ft_strlen((char *)s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	while (i--)
		str[i] = f(i, s[i]);
	return (str);
}
/*
char	up(unsigned int i, char c)
{
	c += i;
	return (c);
}
int	ft_strlen(char *str);

int	main(int ac, char **av)
{
	char	s[] = "hello";

	if (ac != 2)
	{
		printf("pas le bon nombre d'argument");
		return (0);
	}
	printf("%s\n", ft_strmapi(av[1], &up));
}*/
