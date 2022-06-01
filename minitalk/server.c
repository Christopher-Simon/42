/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:59:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/01 21:14:26 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

typedef struct sigaction
{
	void	(*sa_handler)(int);
	void
}

void	sighandler(int signum)
{
	(void)signum;
	write(1, "1\n", 2);
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
	(void)argc;
	(void)argv;

	ft_printf("%d\n", getpid());
	signal(SIGUSR1, sighandler);
	sigaction(SIGUSR1, ,NULL);
	while (1)
		sleep(1);
	return (1);
}
