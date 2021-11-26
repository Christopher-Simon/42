/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:02:53 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/26 17:24:56 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *)src;
	while (n--)
		*((unsigned char *) dest + n) = *(buf + n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);

int	main(void)
{
	char	t[] = "lorem ipum dolor sit a";
	char	t2[] = "lorem ipum dolor sit a";
	char	*dest;
	char	*dest2;
	int		n = 8;
	int		c = 1;
	
	dest = t + 1;
	dest2 = t2 + 1;
	printf("memmove\n");
	memmove(dest, t, n);
//	ft_print_memory(t, sizeof(t), sizeof(t[0]));
	printf("%s\n", dest);

	printf("\nft_memmove\n");
	ft_memmove(dest2, t2, n);
//	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
	printf("\n%s\n", dest2);
}*/
