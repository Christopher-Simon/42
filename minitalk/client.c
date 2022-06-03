/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/03 12:01:33 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

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

// void 	bit_printing(int b)
// {
// 	int	i = 16;

// 	ft_putstr_fd("\n", 1);
// 	while (i-- > 0)
// 		ft_putnbr_fd((b >> i) & 1, 1);
// 	ft_putstr_fd("\n", 1);
// }

int	send_bit(int a, int i)
{
	g_client.i = i;
	while (g_client.i-- > 0)
	{
		g_client.not_resp = 1;
		if (((a >> g_client.i) & 1))
			kill(g_client.serv_pid, SIGUSR1);
		if (!((a >> g_client.i) & 1))
			kill(g_client.serv_pid, SIGUSR2);
		while (g_client.not_resp)
			pause ();
	}
	return (1);
}

int	send_str(void)
{
	int	pos;

	pos = 0;
	while (pos < g_client.len)
		send_bit(g_client.str[pos++], 8);
	return (1);
}

void	sighandler(int signum)
{
	usleep (200);
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
	if (g_client.len == 0)
		return (0);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	send_bit(g_client.len, 32);
	send_str();
	return (1);
}
