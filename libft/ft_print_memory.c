/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:52:10 by chsimon           #+#    #+#             */
/*   Updated: 2021/10/06 18:30:07 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes)
{
	unsigned char	data;
	int		i;

	printf("\n-----Launching ft_print_memory-----");
	i = 0;
	while (i < n)
	{
		if (i % nb_bytes == 0)
			printf("\n");
		data = *((unsigned char *)t + i);
		printf("%02x ", data);
		i++;
	}
}
