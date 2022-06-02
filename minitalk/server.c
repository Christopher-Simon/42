/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/02 03:06:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

typedef struct g_global
{
	int	b;
	int	i;
}	t_global;

	t_global g_serv;


void	sighandler(int signum, siginfo_t *info, void *ucontext_t)
{
	int	b;

	(void)ucontext_t;
	b = 0;
	g_serv.i--;
	// ft_putnbr_fd(g_serv.i, 1);
	if (g_serv.i >= 0)
	{
		// ft_putstr_fd("in", 1);
		// ft_putstr_fd("\n", 1);
		if (signum == SIGUSR1)
		{
			write(1,"1",1);
			b |= (1 << g_serv.i);
		}
		if (signum == SIGUSR2)
		{
			write(1,"0",1);
			b |= (0 << g_serv.i);	
		}
		kill(info->si_pid, SIGUSR1);
	}
	else
	{
		kill(info->si_pid, SIGUSR2);
			int	i = 16;
		ft_putstr_fd("\n", 1);
		while (i-- > 0)
			ft_printf("%d", (b >> i) & 1);
		ft_putstr_fd("\n", 1);
		ft_printf("%d", b);
	}
}

// void	bit_shift_left(int *tab)
// {
// 	char a;

// 	i = 0;
// 	a = 0;
// 	if (SIGUSR1)
// 		a <<= 1;
// 	else
// 	{
// 		a <<= 1;
// 		a++;
// 	}
// 	i++;
// 	ft_printf("a : %d\n", a);
// }
int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_SIGINFO;
	g_serv.i = 16;
	g_serv.b = 0;
	(void)argc;
	(void)argv;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d\n", getpid());
	// signal(SIGUSR1, sighandler);
	while (1)
		sleep(1);
	return (1);
}
