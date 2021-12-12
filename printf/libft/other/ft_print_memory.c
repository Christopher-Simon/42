/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:52:10 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/29 18:48:35 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_print_memory(void *t, size_t n, size_t nb_bytes)
{
	unsigned char		data;
	long unsigned int	i;

	printf("-----Launching ft_print_memory-----\n");
	i = 0;
	while (i < n)
	{
		if (i % nb_bytes == 0)
			//printf("\n");
		data = *((unsigned char *)t + i);
		//printf("%02x ", data);
		printf("%c", data);
		i++;
	}
	printf("\n");
}
