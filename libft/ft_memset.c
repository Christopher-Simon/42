/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:02:43 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/25 12:34:18 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*((unsigned char *)s + i++) = c;
	return (s);
}
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
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
/*
int	main(void)
{
	int	wrong = 0;
	int	i = 0;	
	printf("FT_MEMSET : ");
	char	*str_set[] = {"Hello world", "Hello\0 world", "", "test", "0", NULL};	
	char	*str_set1;
	char	*str_set2;
	int	c[] = {0,-250, 250, -2147483648, 2147483647};
	int	ic;
	int	n;
	while (str_set[i])
	{
		ic = 0;	
		while (ic < 6)
		{		
			n = 0;	
			while (n <= strlen(str_set[i]))
			{
				str_set1 = ft_strdup(str_set[i]);
				str_set2 = ft_strdup(str_set[i]);
				if (memcmp(ft_memset(str_set1, c[ic], n), memset(str_set2, c[ic], n), strlen(str_set[i])) != 0)
					{
						wrong++;
						printf("%s, ", str_set[i]);
					}
				free(str_set1);
				free(str_set2);
				n++;
			}
			ic++;
		}
		i++;
	}	
	if (wrong == 0)
		printf("OK");
	printf("\n");
}*/
