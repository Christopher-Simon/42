/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_printing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:49:00 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/08 14:50:04 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	bit_printing(int b)
{
	int	i;

	i = 16;
	ft_putstr_fd("\n", 1);
	while (i-- > 0)
		ft_putnbr_fd((b >> i) & 1, 1);
	ft_putstr_fd("\n", 1);
}