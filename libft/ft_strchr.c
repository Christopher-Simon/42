/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:17:49 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/11 14:06:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if (*s == c)
		return ((char *)s);
	while (*s++)
		if (*s == c)
			return ((char *)s);
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "Hello \0 world";
	char	c = 'w';
	
	if (strchr(s,c) != NULL)
	{
		printf("%s\n",strchr(s,c));
	}
	else 
	{
		printf("c'est pété\n");
	}
	if (ft_strchr(s,c) != NULL)
	{
		printf("%s\n",ft_strchr(s,c));
	}
	else 
	{
		printf("c'est pété\n");
	}
}*/
