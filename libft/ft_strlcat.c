/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:43:07 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/30 11:57:02 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
size_t	strlcat(char *dst, const char *src, size_t size)
{
	int	len;

	
	len = ft_strlen(src); 
		(size - 1)
	return (ft_strlen(dest));
}*/

#include <stdio.h>
#include <string.h>
#include <bsd/string.h>



int	main(void)
{
	char	src[] = "Hello, ";
	char	dest[25] = "World ! ";
	
	printf("%ld\n",strlcat(src, dest, 25));
	printf("%s\n", dest);
}
