/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:58:33 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/04 17:20:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"


int	main(void)
{
	char	*str = "Hello, world !";
//	printf("\n--%d--\n",printf("Salut à tous,\n%s", str));
	printf("\n--%d--\n",ft_printf("Salut à tous,\n%s", str));
}
