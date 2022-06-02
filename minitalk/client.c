/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/02 18:49:59 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <stdio.h>

typedef struct g_global
{
	int		serv_pid;
	int		b;
	int		i;
	char	*str;
	int		flag;
	int		len;
	int		not_resp;
}	t_global;

t_global	g_client;

void 	bit_printing(int b)
{
	int	i = 16;

	ft_putstr_fd("\n", 1);
	while (i-- > 0)
		ft_putnbr_fd((b >> i) & 1, 1);
	ft_putstr_fd("\n", 1);
}

int	send_bit(int a)
{
	ft_putstr_fd("send bit\n", 1);
	g_client.i = 16;
	ft_putchar_fd(a, 1);
	ft_putstr_fd("\n", 1);
	while (g_client.i-- > 0)
	{
		g_client.not_resp = 1;
		if (((a >> g_client.i) & 1))
			kill(g_client.serv_pid, SIGUSR1);
		if (!((a >> g_client.i) & 1))
			kill(g_client.serv_pid, SIGUSR2);
		while (g_client.not_resp)
			pause ();
		// ft_putnbr_fd(g_client.i, 1);
		// ft_putstr_fd("\n", 1);
	}
	return (1);
}

int	send_str(void)
{
	int	pos;

	ft_putstr_fd("send str\n", 1);
	pos = 0;
	while (pos < g_client.len)
		send_bit(g_client.str[pos++]);
	return (1);
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		g_client.not_resp = 0;
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc <= 2)
		return (0);

	g_client.serv_pid = ft_atoi(argv[1]);
	g_client.str = argv[2];
	g_client.len = ft_strlen(g_client.str);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	ft_putstr_fd("init\n", 1);
	send_bit(g_client.len);
	ft_putstr_fd("init str\n", 1);
	send_str();
	return (1);
}
