/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:40 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/04 21:57:48 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"


int		g_not_resp;

// void 	bit_printing(int b)
// {
// 	int	i = 16;

// 	ft_putstr_fd("\n", 1);
// 	while (i-- > 0)
// 		ft_putnbr_fd((b >> i) & 1, 1);
// 	ft_putstr_fd("\n", 1);
// }

int	send_bit(int a, int i, int serv_pid)
{
	while (i-- > 0)
	{
		g_not_resp = 1;
		if (((a >> i) & 1))
			kill(serv_pid, SIGUSR1);
		if (!((a >> i) & 1))
			kill(serv_pid, SIGUSR2);
		while (g_not_resp)
			pause ();
	}
	return (1);
}

int	send_str(char *str, int len, int serv_pid)
{
	int	pos;

	pos = 0;
	while (pos < len)
		send_bit(str[pos++], 8, serv_pid);
	return (1);
}

void	sighandler(int signum)
{
	usleep (200);
	if (signum == SIGUSR1)
		g_not_resp = 0;
}

int	main(int argc, char **argv)
{
	int		serv_pid;
	char	*str;
	int		len;

	(void)argc;
	if (argc <= 2)
		return (0);
	serv_pid = ft_atoi(argv[1]);
	str = argv[2];
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	send_bit(len, 32, serv_pid);
	send_str(str, len, serv_pid);
	return (1);
}
