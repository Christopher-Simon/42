/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:02:53 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/06 23:48:59 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	const void	*buf;

	i = 0;
	buf = src;
	while (n--)
		*((unsigned char *) dest + i++) = *((unsigned char *) buf + i);
}

/*
#include <stdio.h>
#include <string.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);

int	main(void)
{
	char	t[] = "Hello world !";
	char	t2[] = "Hello world !";

	printf("\nmemmove");
	memmove(t,t + 3, 6);
	ft_print_memory(t, sizeof(t), sizeof(t[0]));
	printf("\nft_memmove");
	ft_memmove(t2,t2 + 3, 6);
	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
	printf("\n%s\n",t);
	printf("%s\n",t2);
}*/
