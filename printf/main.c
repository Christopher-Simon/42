/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2021/12/12 18:58:33 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/04 17:20:54 by chsimon          ###   ########.fr       */
=======
/*   Created: 2021/12/13 11:14:15 by chsimon           #+#    #+#             */
/*   Updated: 2021/12/13 16:53:26 by chsimon          ###   ########.fr       */
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
<<<<<<< HEAD
#include "printf.h"


int	main(void)
{
	char	*str = "Hello, world !";
//	printf("\n--%d--\n",printf("Salut à tous,\n%s", str));
	printf("\n--%d--\n",ft_printf("Salut à tous,\n%s", str));
=======
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
>>>>>>> fb809d5bb07cef213739b9072b9d12535dd19016
}
