/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:16:25 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/13 13:12:32 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

char	**string(char const *s, char c, char **split_tab)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			len = 0;
			while (s[i] && s[i] != c)
			{
				len++;
				i++;
			}
			split_tab[count - 1] = malloc(sizeof(char) * (len + 1));
			if (!s[count - 1])
				return (0);
			split_tab[count - 1][len] = '\0';
		}
		if (s[i])
			i++;
	}
	return (split_tab);
}

char	**fill_string(char const *s, char c, char **split_tab)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			len = 0;
			while (s[i] && s[i] != c)
			{
				split_tab[count - 1][len] = s[i];
				len++;
				i++;
			}
			split_tab[count - 1][len] = '\0';
		}
		if (s[i])
			i++;
	}
	split_tab[count] = '\0';
	return (split_tab);

}

char	**ft_split(char const *s, char c)
{
	int	x;
	char	**split_tab;

	if (!s)
		return (0);
	x = count_word(s, c);
	split_tab = malloc(sizeof(char *) * (x + 1));
	if (!split_tab)
		return (0);
	string(s,c, split_tab);	
	fill_string(s, c, split_tab);
	return (split_tab);
}
/*
int	main(int ac, char **av)
{
	char	**split;
	int	i = 0;
	
	if (ac != 3)
	{
		printf("mauvais arguments");
		return (0);
	}

	split = ft_split(av[1], av[2][0]);
	while (split[i])
	{
	printf("%s\n", split[i++]);
	}
}*/
