/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/02 11:58:59 by chsimon          ###   ########.fr       */
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
}	t_global;

t_global	g_client;

int	send_bit(int a)
{
	g_client.i--;
	if (((a >> g_client.i) & 1))
		kill(g_client.serv_pid, SIGUSR1);
	if (!((a >> g_client.i) & 1))
		kill(g_client.serv_pid, SIGUSR2);
	ft_printf("%d\n",g_client.i);
	return (0);
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
	{
		if 	(g_client.flag == 1)
			send_bit(ft_strlen(g_client.str));
		// if 	(g_client.flag == 2)
		// {
		// 	ft_printf("send 1st char");	
		// 	send_bit(g_client.str[0]);
		// }

	}
	if (signum == SIGUSR2)
	{
		g_client.flag++;
		g_client.i = 16;
		ft_printf("i %d, flag %d, len %d\n", g_client.i, g_client.flag, g_client.len);
		// usleep(20);
		// if (g_client.flag == 2)
		// 	sighandler(SIGUSR1);
		if (g_client.flag == 2)
			exit (1);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	if (argc <= 2)
		return (0);
	g_client.i = 16;
	g_client.serv_pid = ft_atoi(argv[1]);
	g_client.str = argv[2];
	g_client.flag = 1;
	g_client.len = ft_strlen(g_client.str);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	send_bit(g_client.len);
	while (1)
		sleep(1);
	return (1);
}
