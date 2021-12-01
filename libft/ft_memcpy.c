/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:33:38 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/01 21:13:12 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{	
		*((unsigned char *) dest + i) = *((unsigned char *) src + i);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);

int	main(void)
{
	char	t1[] = "hello world!";
	char	t2[] = "hello world!";
	int	t3[] = {5, 6, 7, 8, 9};
	//memmove(t1, t1 + 3, 6);
	memmove(((void*)0), ((void*)0), 3);
	//ft_memcpy(t2, t2 + 3, 6);
	ft_memcpy(((void*)0), ((void*)0), 3);
	printf("\n%s", t1);
	printf("\n%s", t2);
}*/
