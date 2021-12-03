/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:49:12 by chsimon           #+#    #+#             */
/*   Updated: 2021/11/29 15:19:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

void    ft_print_memory(void *t, size_t n, size_t nb_bytes);

int	main(void)
{
	int	i;
	int	wrong;
	char	*str[] = {"Hello world", "Hello\0 world", "", "test", "0", NULL};	
	char	*str1;
	char	*str2;
	int	c[] = {0,-250, 250, -2147483648, 2147483647};
	int	ic;

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
	int	n;

	while (str[i])
	{
		ic = 0;	
		while (ic < 6)
		{		
			n = 0;	
			while (n <= strlen(str[i]))
			{
				str1 = ft_strdup(str[i]);
				str2 = ft_strdup(str[i]);
				ft_memset(str1, c[ic], n);
				memset(str2, c[ic], n);
				if (memcmp(str1, str2, strlen(str[i])) != 0)
					{
						wrong++;
						printf("%s, ", str[i]);
					}
				free(str1);
				free(str2);
				n++;
			}
			ic++;
		}
		i++;
	}	
	if (wrong == 0)
		printf("OK");
	printf("\n");

//FT_BZERO

	wrong = 0;
	i = 0;	
	printf("FT_BZERO : ");

	while (str[i])
	{
		n = 0;	
		while (n <= strlen(str[i]))
		{
			str1 = ft_strdup(str[i]);
			str2 = ft_strdup(str[i]);
			bzero(str1, n);
			ft_bzero(str2, n);
			if (memcmp(str1, str2, strlen(str[i])) != 0)
				{
					wrong++;
					printf("[%s], ", str[i]);
				}
			//printf("%s n : %d\n", str[i], n);
			//ft_print_memory(str1, strlen(str[i]) + 10, sizeof(str1[0]));
			//ft_print_memory(str2, strlen(str[i]) + 10, sizeof(str2[0]));
			//printf("\n");
			free(str1);
			free(str2);
			n++;
		}
		i++;
	}	
	if (wrong == 0)
		printf("OK");
	printf("\n");

//FT_MEMCPY

	wrong = 0;
	i = 0;	
	printf("FT_MEMCPY : ");

	while (str[i])
	{
		n = 0;	
		while (n <= strlen(str[i]))
		{
			str1 = malloc(strlen(str[i]) * (sizeof(char) + 1));
			str2 = malloc(strlen(str[i]) * (sizeof(char) + 1));
			if (memcmp(memcpy(str1, str[i], n),ft_memcpy(str2, str[i], n), n) != 0)
				{
					wrong++;
					printf("[%s], n : %d ", str[i], n);
				}
			//printf("%s n : %d\n", str[i], n);
			//printf("   memcpy : ");
			//ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
			//printf("ft_memcpy : ");
			//ft_print_memory(str2, strlen(str2), sizeof(str2[0]));
			//printf("\n");
			free(str1);
			free(str2);
			n++;
		}
		
		i++;
	}
	i = 0;
	while (str[i])
	{
	ic = 0;
		while (ic <= strlen(str[i]))
		{
		n = 0;
			while (n <= strlen(str[i]))
			{
				str1 = ft_strdup(str[i]);
				str2 = ft_strdup(str[i]);
				if (memcmp(memcpy(&str1[ic], str1,n),ft_memcpy(&str2[ic], str1,n), strlen(str1)) != 0)
				{
					wrong++;
					printf("[%s], n : %d ", str[i], n);
				}
				//printf("   avant : ");
				//ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
				//printf("%s ic : %d -  n : %d\n", str[i], ic, n);
				//printf("   memcpy : ");
				//ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
				//printf("ft_memcpy : ");
				//ft_print_memory(str2, strlen(str2), sizeof(str2[0]));
				//printf("\n");
				n++;
			}
		ic++;
		}
	i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");

//FT_MEMOVE
	wrong = 0;
	i = 0;	
	printf("FT_MEMMOVE : ");

	while (str[i])
	{
		n = 0;	
		while (n <= strlen(str[i]))
		{
			str1 = malloc(strlen(str[i]) * (sizeof(char) + 1));
			str2 = malloc(strlen(str[i]) * (sizeof(char) + 1));
			if (memcmp(memmove(str1, str[i], n),ft_memmove(str2, str[i], n), n) != 0)
				{
					wrong++;
					printf("[%s], n : %d ", str[i], n);
				}
			//printf("%s n : %d\n", str[i], n);
			//printf("   memmove : ");
			//ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
			//printf("ft_memmove : ");
			//ft_print_memory(str2, strlen(str2), sizeof(str2[0]));
			//printf("\n");
			free(str1);
			free(str2);
			n++;
		}
		
		i++;
	}
	i = 0;
	while (str[i])
	{
	ic = 0;
		while (ic <= strlen(str[i]))
		{
		n = 0;
			while (n <= strlen(str[i]))
			{
				str1 = ft_strdup(str[i]);
				str2 = ft_strdup(str[i]);
				if (memcmp(memmove(&str1[ic], str1,n),ft_memmove(&str2[ic], str1,n), strlen(str1)) != 0)
				{
					wrong++;
					printf("[%s], n : %d ", str[i], n);
				}
				//printf("   avant : ");
				//ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
				//printf("%s ic : %d -  n : %d\n", str[i], ic, n);
				//printf("   memmove : ");
				//ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
				//printf("ft_memmove : ");
				//ft_print_memory(str2, strlen(str2), sizeof(str2[0]));
				//printf("\n");
				n++;
			}
		ic++;
		}
	i++;
	}
	if (wrong == 0)
		printf("OK");
	printf("\n");

//FT_STRLCPY
	wrong = 0;
	i = 0;	
	printf("FT_STRLCPY : ");
	
	while (str[i])
	{
		n = 0;
		while (n <= strlen(str[i]) + 5)
		{
			str1 = malloc(strlen(str[i]) * (sizeof(char) + 1));
			str2 = malloc(strlen(str[i]) * (sizeof(char) + 1));
			strlcpy(str1, str[i], n);
			ft_strlcpy(str2, str[i], n);
			if (memcmp(str1, str2, strlen(str1)) != 0)
			{
				wrong++;
				printf("[%s], n : %d ", str[i], n);
			}/*
			printf("   avant : \n");
			ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
			ft_print_memory(str2, strlen(str1), sizeof(str1[0]));
			printf("%s n : %d\n", str[i], n);
			printf("   strlcpy : ");
			ft_print_memory(str1, strlen(str1), sizeof(str1[0]));
			printf("ft_strlcpy : ");
			ft_print_memory(str2, strlen(str2), sizeof(str2[0]));
			printf("\n");*/
			free(str1);
			free(str2);
			n++;
		}
		i++;
	}



	if (wrong == 0)
		printf("OK");
	printf("\n");



}

//FT_ATOI
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	const char *str[] = {"0", "1", "5", "-1", "-5", "10", "-10", "-1000", "1000", "-2147483648","2147483647", "-2147483649","2147483648", "-54705", "546", "-4452", "548", "-5246", "5246", "-452", "-253", "00074", "+-54", "546:4","-+48", "--47", "++47", "+47+5", "\e475", "\t\n\r\v\f  469 \n","\n\n\n  -46\b9 \n5d6", "", "\f469",NULL};
	int	i;
//	if (ac != 2)
//	{
//		printf("gros boulet");
//		return(0);
//	}
	i = 0;
	while (str[i])
	{
		printf("------");
		if( atoi(str[i]) == ft_atoi(str[i]))
			printf("OK -> ");
		else
			printf("KO -> ");
		printf("atoi : %d | %d : ft_atoi\n", atoi(str[i]), ft_atoi(str[i]));
	i++;
	}
}
