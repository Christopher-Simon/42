/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:52:04 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/07 18:15:26 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return ('\0');
}

/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	char	big[] = "Hello'\0' world!";
	char	little[] = "world";
	int	len;

	printf("strnstr :%s\n",strnstr(big, little, sizeof(big)));
	printf("ft_     :%s\n",ft_strnstr(big, little, sizeof(big)));
}*/
