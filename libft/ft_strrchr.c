/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:40:50 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/11 14:05:47 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)&s[len]);
		len--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = "Hello world";
	char	c = 'H';
	
	if (strrchr(s,c) != NULL)
	{
		printf("%s\n",strrchr(s,c));
	}
	else 
	{
		printf("c'est pété\n");
	}
	if (ft_strrchr(s,c) != NULL)
	{
		printf("%s\n",ft_strrchr(s,c));
	}
	else 
	{
		printf("c'est pété\n");
	}
}*/
