/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:57:02 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/07 00:24:50 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "HeLlo world!";
	int	i;	

	i = 0;
	printf("%s\n", str);
	while(str[i])
		printf("%c", toupper(str[i++]));
	i = 0;
	printf("\n");
	while(str[i])
		printf("%c", ft_toupper(str[i++]));
}*/
