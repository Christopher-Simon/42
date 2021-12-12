/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:58:33 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/13 00:45:30 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_printf(const char *s, ...);

int	main(void)
{
	char	*str = "Hello, world !";
	printf(" %d\n",printf("Salut à tous,\n%s", str));
	printf(" %d\n",ft_printf("Salut à tous,\n%s", str));
}
