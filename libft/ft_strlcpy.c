/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:23:30 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/29 18:13:04 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!src[i])
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	src[] = "";
	char	dest[15] = "rrrrr";
	char	*dest2;

	printf("%d\n",ft_strlcpy(dest, src, 15));
	//strlcpy(dest2, src, 15);
	printf("%s", dest);	
	//printf("%s", dest2);	
}*/
