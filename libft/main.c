/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:49:12 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/24 20:31:37 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int	wrong;

// FT_ISALPHA
	wrong = 0;
	i = 0;
	printf("FT_ISALPHA : ");
	while (i <= 225)
	{	
		if (isalpha(i) == 0)
		{
			if (ft_isalpha(i) != 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
		 if (isalpha(i) != 0)
		{
			if (ft_isalpha(i) == 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
				i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");

// FT_ISDIGIT
	wrong = 0;
	i = 0;
	printf("FT_ISDIGIT : ");
	while (i <= 225)
	{	
		if (isdigit(i) == 0)
		{
			if (ft_isdigit(i) != 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
		if (isdigit(i) != 0)
		{
			if (ft_isdigit(i) == 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
		i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");


// FT_ISALNUM
	wrong = 0;
	i = 0;
	printf("FT_ISALNUM : ");
	while (i <= 225)
	{
		if (isalnum(i) == 0)
		{
			if (ft_isalnum(i) != 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
		if (isalnum(i) != 0)
		{
			if (ft_isalnum(i) == 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}
		i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");

// FT_ISASCII
	wrong = 0;
	i = 0;
	printf("FT_ISASCII : ");
	while (i <= 225)
	{
		if (isascii(i) == 0)
		{
			if (ft_isascii(i) != 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
		if (isascii(i) != 0)
		{
			if (ft_isascii(i) == 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}
		i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");

// FT_ISPRINT
	wrong = 0;
	i = 0;
	printf("FT_ISPRINT : ");
	while (i <= 225)
	{
		if (isprint(i) == 0)
		{
			if (ft_isprint(i) != 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}		
		if (isprint(i) != 0)
		{
			if (ft_isprint(i) == 0)
			{
				printf("%d,", i);	
				wrong++;
			}
		}
		i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");

// FT_STRLEN
	wrong = 0;
	i = 0;	
	char *strlen1[] = {"Hello\0 world", "", "test", "0", NULL};
		
	printf("FT_STRLEN : ");
	while (strlen1[i])
	{
		if (ft_strlen(strlen1[i]) != strlen(strlen1[i]))
		{	
			printf("%s, ", strlen1[i]);
			wrong++;	
		}
		i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");
	
//FT_MEMSET
	wrong = 0;
	i = 0;	
	printf("FT_MEMSET : ");
	char *str_set[] = {"Hello world", "Hello\0 world", "", "test", "0", NULL};		
	int c[] = {0,-250, 250, -2147483648, 2147483647};
	int ic;
	int n;
	while (str_set[i])
	{
		n = 0;				
		while (n <= strlen(str_set[i]))
		{
			printf("%ld\n", strlen(str_set[i]));
			ic = 0;
			while (ic < 6)
			{
				printf("%d-%d-%d\n", i, n, ic);	
				if (memcmp(ft_memset(str_set, c[ic], n), memset(str_set, c[ic], n), sizeof(str_set) != 0))
					{
						wrong++;
						printf("%s, ", str_set[i]);
					}
			ic++;
			}
			n++;
		}
		i++;
	}	
	if (wrong == 0)
		printf("OK");
	printf("\n");
}
