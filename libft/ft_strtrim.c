/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:30:11 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/13 20:38:29 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(char *str);

#include <stdio.h>

int	count_start(char const *s1, char const *set, int i )
{
	while (s1[i])
	{
		if (s1[i] == set[i])
			i++;
		else
			
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	j;
	int	set_len;	
	char	*trim;

	len = ft_strlen((char *)s1);
	i = 0;
	j = 2;	
	count_start(s1, set, i);	
	trim = ft_substr((char *)s1, i, len - i - j);
	return (trim);
}


int	main(void)
{
	char	s1[] = "Hello worldHe";
	char	set[] = "He";
	char	*trim;
	
	trim = ft_strtrim(s1, set);
	printf("%s\n", trim);


}
