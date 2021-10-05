/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:02:43 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/06 01:39:26 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memset(void *s, int c, size_t n)
{
	
}

#include <string.h>
#include <stdio.h>

void	print_memory(int *t, size_t n)
{
	unsigned char	data;
	int	i;

	printf("sizeof t : %ld", n);
	i = 0;
	printf("%ls" ,t);
	printf("%s", &t);
/*	while(i < n)
	{
		data = &t 
		i++;
	}*/
}

int	main (void)
{
	int 	t[] = {1, 2, 8, 5, 10000};
	int	c;
	size_t	n;

	c = 0;
	n = 1;
	printf("sizeof t : %ld\n", sizeof(t));
	print_memory(t, sizeof(t));
	memset(t, c, sizeof(t));
//	printf("%d %d", t[0], t[1]);
}
