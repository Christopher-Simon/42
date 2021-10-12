/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:12:50 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/13 00:46:35 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, (char *)&s[start], (len + 1));
	return (sub);
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello world!";
	char	*sub;

	sub = ft_substr(str, 111, 6);
	printf("%s\n", sub);	
	free(sub);
}*/
