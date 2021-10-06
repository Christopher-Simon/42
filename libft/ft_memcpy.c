/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:33:38 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/06 19:48:29 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		*((unsigned char *) dest + i++) = *((unsigned char *) src + i);
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes);

int	main(void)
{
	int	t1[] = {0, 1, 2, 3};
	int	t2[] = {5, 6, 7, 8, 9};
	int	t3[] = {5, 6, 7, 8, 9};

	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));
	memcpy(t2, t1, sizeof(t1));
	ft_print_memory(t2, sizeof(t2), sizeof(t2[0]));

	ft_print_memory(t3, sizeof(t3), sizeof(t3[0]));
	ft_memcpy(t3, t1, sizeof(t1));
	ft_print_memory(t3, sizeof(t3), sizeof(t3[0]));


}*/
