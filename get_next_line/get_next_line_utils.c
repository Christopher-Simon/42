/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:04:52 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/08 16:59:24 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int i;
    
	if (!s)
		return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
        size_t  i;

        i = 0;
        if (size <= 0)
                return (ft_strlen(src));
        while (src[i] && i < size - 1)
        {
                dst[i] = src[i];
                i++;
        }
        dst[i] = '\0';
        return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*s_join;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	s_join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!s_join)
		return (0);
	ft_strlcpy(s_join, (char *)s1, (len1) + 1);
	ft_strlcpy(&s_join[len1], (char *)s2, len2 + 1);
	return (s_join);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*copy;
	int	    i;
    size_t  n;

    n = nmemb * size;
	i = 0;
	copy = malloc(nmemb * size);
	if (!copy)
		return (0);
	while (n--)
		*((unsigned char *)copy + i++) = '\0';
	return (copy);
}