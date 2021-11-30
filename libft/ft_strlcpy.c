/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 21:23:30 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/30 16:08:19 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < size && src[0])
	{
		dst[i] = '\0';
		i++;
	}
	if (!src[0])
		dst[0] = '\0';
	return (ft_strlen(src));
}
/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	src[] = "";
	char	dest[15] = "rrrrrr\0\0\0\0\0\0\0";
	char	dest2[15] = "rrrrrr\0\0\0\0\0\0\0";

	printf("%ld\n", ft_strlcpy(dest, src, 15));
	printf("%ld\n", strlcpy(dest2, src, 15));
	printf("%s\n", &dest[1]);	
	printf("%s\n", &dest2[1]);	
}*/
