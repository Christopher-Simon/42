/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:28:14 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/09 15:52:10 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*get_buf(int fd, char *buf, int *final)
{
	int		ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret < 0)
		return (NULL);
	if (ret == 0)
		(*final)++;
	buf[ret] = '\0';
	return (buf);
}

char	*backtrack(int fd, char *buf, char *memory, int *final)
{
	char	*line;
	size_t	i;

	if (ft_strchr(memory, '\n') == 0)
	{
		if (!get_buf(fd, buf, final))
		{
			free (memory);
			line = ft_calloc(sizeof(char), 1);
			return (line);
		}
	}
	else
		return (memory);
	i = 0;
	line = ft_strjoin(memory, buf);
	free (memory);
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (*final == 0 && ft_strchr(line, '\n') == 0  )
		line = backtrack(fd, buf, line, final);
	return (line);
}

char	*get_next_line_suite(char *memory, char *line, size_t *i)
{
	(*i) = 0;
	while (line[(*i)] && line[(*i)] != '\n')
		(*i)++;
	memory = malloc(sizeof(char) * (ft_strlen(line) - (*i) + 1));
	if (!memory)
	{
		free (line);
		return (NULL);
	}
	return (memory);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	size_t		i;
	static char	*memory;
	int			final;

	final = 0;
	if (!memory)
		memory = ft_calloc(sizeof(char), 1);
	line = backtrack(fd, buf, memory, &final);
	if (!*line)
	{
		free (line);
		return (NULL);
	}
	memory = get_next_line_suite(memory, line, &i);
	if (!memory)
		return (NULL);
	if (!final)
	{
		ft_strlcpy(memory, &line[i + 1], ft_strlen(line) - i + 1);
		line[i + 1] = '\0';
	}
	else
		ft_strlcpy(memory, &line[i], ft_strlen(line) - i + 1);
	return (line);
}
