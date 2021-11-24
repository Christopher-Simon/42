/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:30:11 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/24 18:27:35 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	trim_start(char const *s1, char const *set,int s1len)
{
	int	i;
	int	j;
	int	len;
	
	len = ft_strlen((char *)set);
	j = 0;
	i = 0;
	while ( ft_strncmp((char *)&s1[j], set, len) == 0)
	{	
		i++;
		j += len;
	}
	return (j);
}

int	trim_end(char const *s1, char const *set,int s1len)
{
	int	i;
	int	k;
	int	len;
	
	len = ft_strlen((char *)set);
	k = 0;
	i = 0;
	while (ft_strncmp((char *)&s1[s1len - len -  (i * len)], set, len) == 0)
	{	
		i++;
		k += len;
	}
	return (k);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	int	s1len;
	int	j;
	int	k;
	char	*trim;

	s1len = ft_strlen((char *)s1);
	if (set[0] == '\0')
	{
		trim = ft_substr((char *)s1, 0, s1len);
		return (trim);
	}
	k = trim_end((char *)s1, (char *)set, s1len);
	j = trim_start((char *)s1, (char *)set, s1len);
	trim = ft_substr((char *)s1, j, s1len - j - k);
	return (trim);
}

/*
#include <stdio.h>
int	main(int ac, char **av)
{
	
	char	s1[] = "HeHeHhello, world!HeqHeHe";
	char	set[] = "He";
	
	char	*trim;
	
	if (ac != 3)
	{
		printf("Mauvais arguments");
		return (0);
	}
	trim = ft_strtrim(av[1], av[2]);
	printf("%s\n", trim);
}*/
