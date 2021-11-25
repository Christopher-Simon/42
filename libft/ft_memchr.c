/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:44:09 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/25 19:35:30 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;

	i = 0;
	if (*(unsigned char *)s == (unsigned char)c)
		return ((unsigned char *)s);
	while (i < n && *((unsigned char *)s + i++) != (unsigned char)c)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			return ((unsigned char *)s + i);
		}
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);


int	main(void)
{
	int	t[] = {2, 128, 2147483647, 3};

	int c = -2147483648;
	printf("c = %x\n", (unsigned char)c);
	ft_print_memory(t, sizeof(t), sizeof(t[0]));
	if (memchr(t, c, sizeof(t))==0)
		printf("\nis 0\n");
	else
		printf("\nis found\n");
	if (ft_memchr(t, c, sizeof(t))==0)
		printf("is 0");
	else
		printf("is found");
}*/
