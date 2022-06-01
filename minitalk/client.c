/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/01 20:50:08 by chsimon          ###   ########.fr       */
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
b >>= 1;
// 	b->i--;
// }

// unsigned char	bit_r(unsigned char a)
// {
// 	unsigned char	b;

// 	ft_putnbr_base(a, "01");
// 	ft_printf("\n_______________END______________\n");
// 	return (1);
// }

// void	sighandler(int signum)
// {
// 	(void)signum;
// 	ft_printf("C'est fini, j'envoie la suite\n");
// 	test_acc_recep(g_test.serv_pid);
// }

int	test_acc_recep(void)
{
	while (g_test.i-- > 0)
	{
		kill(g_test.serv_pid, SIGUSR1);
		sleep(1);
	}
	// signal(SIGUSR1, sighandler);
	return (1);
}

int	main(int argc, char **argv)
{
	(void)argc;
	g_test.i = 3;
	g_test.serv_pid = ft_atoi(argv[1]);
	test_acc_recep();
	return (1);
}

	// kill(ft_atoi(argv[1]), SIGUSR1);
