/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:02:43 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/24 19:58:45 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*((unsigned char *)s + i++) = c;
	return (s);
}

/*
#include <string.h>
#include <stdio.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	int i;

	i = n;
	printf("%x\n", *(unsigned char*)s1);
	while (n-- && (*(unsigned char*)s1++ == *(unsigned char*)s2++))
		if (n == 0)
			return (1);
	printf("fails at the byte %ld\n", i - n - 1);
	return (0);
}

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
		data = *((unsigned char*)t+i);
		printf("%02x ", data);	
		i++;
	}
}

int	main (void)
{
	int 	t1[] = {1001, 500000, 9, 9, 1};
	int 	t2[] = {1001, 500000, 9, 9, 1};
	char 	c1[] = "Hello, Karine ! ";
	char 	c2[] = "Hello, Karine ! ";
	int	c;
	size_t	n;

	c = 0;
	n = 5;
	print_memory(t1, sizeof(t1), sizeof(t1[0]));
	memset(t1, c, n);
	print_memory(t1, sizeof(t1), sizeof(t1[0]));
	
	print_memory(t2, sizeof(t2), sizeof(t2[0]));
	ft_memset(t2, c, n);
	print_memory(t2, sizeof(t2), sizeof(t2[0]));
	printf("\n----\n");
	printf("%d\n", memcmp(t1, t2, sizeof(t2)));
}*/
