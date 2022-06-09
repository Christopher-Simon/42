/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/09 21:43:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <stdio.h>

int	g_not_resp;

int	is_correct_pid(void)
{
	usleep(20);
	if (g_not_resp)
	{
		ft_putendl_fd("Probably wrong PID", 1);
		exit (1);
	}
	return (1);
}

int	send_bit(int a, int i, int serv_pid, int active)
{
	
	while (i-- > 0)
	{
		while (g_not_resp)
		{
			if (active == 0)
				is_correct_pid();
			active = 1;
		}
		g_not_resp = 1;
		if (((a >> i) & 1))
			kill(serv_pid, SIGUSR1);
		if (!((a >> i) & 1))
			kill(serv_pid, SIGUSR2);
	}
	return (1);
}

int	send_str(char *str, int len, int serv_pid)
{
	int	pos;

	pos = 0;
	while (pos < len)
		send_bit(str[pos++], 8, serv_pid, 1);
	return (1);
}

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		g_not_resp = 0;
}

int	main(int argc, char **argv)
{
	int		serv_pid;
	char	*str;
	int		len;

	(void)argc;
	g_not_resp = 0;
	if (argc <= 2)
		return (0);
	serv_pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	send_bit(len, 32, serv_pid, 0);
	send_str(str, len, serv_pid);
	return (1);
}
