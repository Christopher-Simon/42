/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:58:33 by chsimon           #+#    #+#             */
/*   Updated: 2022/03/16 18:12:08 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"


int	main(void)
{
	int y = -2147483648;
	// char *y = "Hello, world !";
	char	*str = "%+ 040.20d";

	printf("\n");
	printf("\ntaille: %d", ft_printf(str, y));
	printf("\n");
	printf("\ntaille: %d", printf(str, y));
	printf("\n");

/*
-433000444
0x5579e630f004
unsigned long int max : 9223372036854775807
Flags :
The -	: For the width, align the number on the left.
The +	: Add a '+' in front of positive signed numeric types
The ' '	: For the width, add a space
The 0	: For the width, adds 0s
The #	: for X and x  
The .	: Precision : Adds 0s inside the width (makes it bigger if needed), can't use 0 with it

%c :	W 
%s :	W
%p :	W
%d :	W. -0 +
%i :	W. -0 +
%u :	W. -0 +
%x :	W.#-0+
%X :	W.#-0


	char	*str = "Hello, world !";
	printf("\n--%d--\n",printf("Salut à tous,\n%s", str));
	printf("\n--%d--\n",ft_printf("Salut à tous,\n%s", str));
	
int d = 42;

The Precision flag
	printf("%5d|5d\n", d);
	printf("%-5d|-5d\n", d);
	printf("%+5d|+5d\n", d);
	printf("%05d|05d\n", d);

	printf("\n===============\n\n");

	printf("%-5d|-5d\n", d);
	printf("%+-5d|+-5d\n", d);
	char *format = "%5.5d|5.5d\n";
	printf(format, d);
	printf("%-5d|05d\n", d);
	printf("%-5d|-5d\n", d);

	printf("\n===============\n\n");
	
	printf("%5.4d|5.4d\n", d);
	printf("%.5d|.5d\n", d);
	printf("%2.5d|2.5d\n", d);

	printf("\n===============\n\n");

	printf("%5dd|5d\n", d);
	printf("%-.5d|-.5d\n", d);
	printf("% .5d| .5d\n", d);

	printf("%0 5d|0 5d\n", d);
	printf("% 05d| 05d\n", d);
	printf("%0 5d|0 5d\n", d);
	printf("%05d|05d\n", d);
	printf("%- 5d|- 5d\n", d);
*/
}
