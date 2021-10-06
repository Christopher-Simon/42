/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:02:43 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/06 13:20:12 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*((unsigned char*)s + i++) = c;
	return (s);
}

#include <string.h>
#include <stdio.h>

void	print_memory(void *t, size_t n, size_t nb_bytes)
{
	unsigned char	data;
	int	i;

	printf("\n-----Launching ft_print_memory-----");
	i = 0;
	while(i < n)
	{
		if (i % nb_bytes == 0)
			printf("\n");
		data = *(((unsigned char*)t)+i);
		printf("%02x ", data);	
		i++;
	}
/*	printf("\n-----Launching ft_print_memory tests-----");
	i = 0;
	while(i < n)
	{
		if (i % nb_bytes == 0)
			printf("\n");
		data = *(((unsigned char*)t)+i);
		printf("%02d ", data);	
		i++;
	}*/
}

int	main (void)
{
	int 	t1[] = {1001, 500000, 9, 9, 1};
	int 	t2[] = {1001, 500000, 9, 9, 1};
	int	c;
	size_t	n;

	c = 27500000;
	n = 5;
	print_memory(t1, sizeof(t1), sizeof(t1[0]));
	memset(t1, c, n);
	print_memory(t1, sizeof(t1), sizeof(t1[0]));
	print_memory(t2, sizeof(t2), sizeof(t2[0]));
	ft_memset(t2, c, n);
	print_memory(t2, sizeof(t2), sizeof(t2[0]));
}
