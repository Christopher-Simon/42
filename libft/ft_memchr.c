/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:44:09 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/07 01:01:43 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (*((unsigned char *)s + i) != (unsigned char)c)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)&s + i);
		i++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	t[] = {0, 1, 2, 3};

	int c = 1;
	printf("%p\n", memchr(t, c, sizeof(t)));
	printf("%p\n", ft_memchr(t, c, sizeof(t)));
}
