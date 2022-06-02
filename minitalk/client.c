/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/02 03:03:13 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <stdio.h>

typedef struct g_global
{
	int				serv_pid;
	unsigned char	b;
	int				i;
}	t_global;

t_global	g_test;

// void	bit_le_routeur(int a)
// {
// 	t_char	b;

// 	b->b >> i = a;
// 	b->i--;
// }

// unsigned char	bit_r(unsigned char a)
// {
// 	unsigned char	b;

// 	ft_putnbr_base(a, "01");
// 	ft_printf("\n_______________END______________\n");
// 	return (1);
// }


int	test(int a)
{
	ft_printf("_______________TEST________________\n");
	ft_putnbr_base(a, "01");
	ft_printf("\n%d\n", a);
	// a >>= 1;
	g_test.i--;
	ft_printf("i : %d\n", g_test.i);
	ft_printf("%d", (a >> g_test.i) & 1);
	if (((a >> g_test.i) & 1))
		kill(g_test.serv_pid, SIGUSR1);
	if (!((a >> g_test.i) & 1))
		kill(g_test.serv_pid, SIGUSR2);
	ft_printf("\n%d\n", (a >> g_test.i) & 1);
	ft_printf("\n");
	// int	b;
	
	// b = 0;
	// b |= (((a >> i) & 1) << i);
	// i = 16;
	// while (i-- > 0)
	// 	ft_printf("%d", (b >> i) & 1);
	return (1);
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1) 
		test(253);
	if (signum == SIGUSR2)
		exit (1);

}

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc <= 1)
		return (0);
	ft_putnbr_base(2147483647, "01");
	ft_printf("\n%d\n", getpid());
	g_test.i = 16;
	g_test.serv_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	test(253);
	while (1)
		sleep(1);
	return (1);
}
	// 1111 1111 1111 1111 1111 1111 1111 111
	// kill(ft_atoi(argv[1]), SIGUSR1);
