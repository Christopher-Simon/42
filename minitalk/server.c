/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/02 19:26:46 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

typedef struct g_global
{
	int		b;
	int		i;
	char	*str;
	int		o_z;
	int		c_pid;
	int		recep;
	int		len;
}	t_global;

t_global g_serv;

void 	bit_printing(int b)
{
	int	i = 16;

	ft_putstr_fd("\n", 1);
	while (i-- > 0)
		ft_putnbr_fd((b >> i) & 1, 1);
	ft_putstr_fd("\n", 1);
}

int	get_bit(void)
{
	ft_putstr_fd("recep bit\n", 1);
	g_serv.i = 32;
	while (g_serv.i-- > 0)
	{
		while (g_serv.recep)
			usleep (1000);
		if (g_serv.o_z)
			g_serv.b |= (1 << g_serv.i);
		if (!g_serv.o_z)
			g_serv.b |= (0 << g_serv.i);
		kill(g_serv.c_pid , SIGUSR1);
		g_serv.recep = 1;
		// ft_putnbr_fd(g_serv.o_z, 1);
		// ft_putnbr_fd(g_serv.i, 1);
		// ft_putstr_fd("\n", 1);
	}
	// ft_putnbr_fd(g_serv.b, 1);
	// ft_putchar_fd(g_serv.b, 1);
	// ft_putstr_fd("\n", 1);
	return (g_serv.b);
}

void	fill_str(void)
{
	int	pos;

	ft_putstr_fd("recep str\n", 1);
	pos = 0;
	while (pos < g_serv.len)
	{
		g_serv.b = 0;
		g_serv.str[pos++] = get_bit();
	}
	ft_putstr_fd(g_serv.str, 1);
}

void	sighandler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	g_serv.c_pid = info->si_pid;
	if (signum == SIGUSR1)
		g_serv.o_z = 1;
	if (signum == SIGUSR2)
		g_serv.o_z = 0;
	g_serv.recep = 0;
}

int	main(void)
{
	struct sigaction	sa;
	int					zizid;

	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_SIGINFO;
	g_serv.i = 32;
	g_serv.recep = 1;
	zizid = getpid();
	if (zizid < 0)
		return (0);
	ft_printf("%d\n", zizid);
	ft_putstr_fd("init\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_serv.len = get_bit();
	g_serv.str = ft_calloc(g_serv.len, sizeof(char) + 1);
	if (!g_serv.str)
		return (0);
	ft_putstr_fd("init str\n", 1);
	fill_str();
	return (1);
}
