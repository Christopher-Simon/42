/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:25:25 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/07 00:27:05 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
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
		printf("%c", tolower(str[i++]));
	i = 0;
	printf("\n");
	while(str[i])
		printf("%c", ft_tolower(str[i++]));
}*/
