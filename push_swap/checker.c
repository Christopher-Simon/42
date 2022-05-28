/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:57 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/27 20:41:48 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned long int	i;

    i = 0;
    if (n == 0)
		return (0);
    if (!s1[i])
		return (s1[i] - s2[i]);
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	get_instructions(char *instructions)
{
	ft_strncmp("sa");
	ft_strncmp("sb");
	ft_strncmp("pa");
	ft_strncmp("pb");
	ft_strncmp("ra");
	ft_strncmp("rb");
	ft_strncmp("rr");
	ft_strncmp("rra");
	ft_strncmp("rrb");
	ft_strncmp("rrr");
}

int	main(int argc, char **argv)
{
	char	*instructions;

	while (instructions = get_next_line(0))
	{
		printf("%s", instructions);
		free(instructions);
	}
	return (1);
}