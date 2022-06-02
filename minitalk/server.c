/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/02 14:04:25 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

typedef struct g_global
{
	int		b;
	int		i;
	char	*str;
	int		flag;
	int		len;
}	t_global;

t_global g_serv;

void 	bit_printing(int b)
{
	int	i = 16;

	ft_putstr_fd("\n", 1);
	while (i-- > 0)
		ft_printf("%d", (b >> i) & 1);
	ft_putstr_fd("\n", 1);
}

int	get_bit(int signum, siginfo_t *info)
{
	g_serv.i--;
	if (g_serv.i >= 0)
	{
		if (signum == SIGUSR1)
			g_serv.b |= (1 << g_serv.i);
		if (signum == SIGUSR2)
			g_serv.b |= (0 << g_serv.i);
		usleep(20);
		kill(info->si_pid, SIGUSR1);
	}
	else
	{
		ft_printf("\n%d\n", g_serv.b);
		ft_printf("\n%c\n", g_serv.b);
		g_serv.i = 16;
		return (1);
	}
	bit_printing(g_serv.b);
	return (0);
}

int	create_str(void)
{
	ft_printf("malloc de %d done\n", g_serv.b);
	g_serv.str = ft_calloc(g_serv.b, sizeof(char));
	if (!g_serv.str)
		exit (0);
	return (1);
}

void	sighandler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	if (get_bit(signum, info) && g_serv.flag == 1)
	{
		ft_printf("step 1\n");
		create_str();
		g_serv.flag++;
		g_serv.i = 16;
		g_serv.b = 0;
		ft_printf("i %d flag %d b %d", g_serv.i, g_serv.flag, g_serv.b);
		usleep(20);
		kill(info->si_pid, SIGUSR2);
	}
	// if (get_bit(signum, info) && g_serv.flag == 2)
	// {
	// 	ft_printf("step 2");
	// 	ft_printf("%c\n", g_serv.b);
	// 	usleep(20);
	// 	kill(info->si_pid, SIGUSR2);
	// }
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_SIGINFO;
	g_serv.i = 16;
	g_serv.b = 0;
	g_serv.flag = 1;
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (1);
}
