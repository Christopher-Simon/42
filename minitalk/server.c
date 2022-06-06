/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/06 19:13:13 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

typedef struct g_global
{
	int		o_z;
	int		c_pid;
	int		recep;
}	t_global;

t_global	g_serv;

// void	bit_printing(int b)
// {
// 	int	i = 16;

// 	ft_putstr_fd("\n", 1);
// 	while (i-- > 0)
// 		ft_putnbr_fd((b >> i) & 1, 1);
// 	ft_putstr_fd("\n", 1);
// }

int	get_bit(int b, int i)
{
	g_serv.recep = 1;
	while (i-- > 0)
	{
		while (g_serv.recep)
			pause ();
		if (g_serv.o_z)
			b |= (1 << i);
		if (!g_serv.o_z)
			b |= (0 << i);
		kill(g_serv.c_pid, SIGUSR1);
		g_serv.recep = 1;
	}
	return (b);
}

void	fill_str(int len, char *str)
{
	int	pos;

	pos = 0;
	while (pos < len)
		str[pos++] = get_bit(0, 8);
	ft_putendl_fd(str, 1);
	free(str);
}

void	sighandler(int signum, siginfo_t *info, void *ucontext_t)
{
	(void)ucontext_t;
	g_serv.c_pid = info->si_pid;
	if (signum == SIGUSR1)
		g_serv.o_z = 1;
	if (signum == SIGUSR2)
		g_serv.o_z = 0;
	usleep (20);
	g_serv.recep = 0;
}

int	server_loop(void)
{
	char	*str;
	int		len;

	len = get_bit(0,32);
	str = ft_calloc(len, sizeof(char) + 1);
	if (!str)
		return (0);
	fill_str(len, str);
	server_loop();
	return (1);
}

int	main(void)
{
	struct sigaction	sa;
	int					serv_id;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_SIGINFO;
	serv_id = getpid();
	if (serv_id < 0)
		return (0);
	ft_printf("%d\n", serv_id);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	server_loop();
	return (1);
}
