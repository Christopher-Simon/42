/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:14:15 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/13 16:53:26 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char			c = 'c';
	char			str[] = "Test";
	int				i = -42;
	unsigned int	u = 42;

	//printf("- %d\n", printf("Hello, World! %s", str));
	//printf("- %d\n", ft_printf("Hello, World! %s", str));
	printf("%c %s %p %d %i %u %x %X %% \n", c, str, c, i, u, i, i, i, str);
	printf("%18c %#s %#p %#d %#i %#u %#x %#X %#% \n", c, str, c, i, u, i, i, i, str);
	printf("% c % s % p % d % i % u % x % X % % \n", c, str, c, i, u, i, i, i, str);
	printf("%+c %+s %+p %+d %+i %+u %+x %+X %+% \n", c, str, c, i, u, i, i, i, str);
}
