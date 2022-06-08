/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:01:10 by chsimon           #+#    #+#             */
/*   Updated: 2022/06/08 14:50:58 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include "ft_my_lib.h"
# include <sys/types.h>
# include <signal.h>

typedef struct g_global
{
	int		o_z;
	int		c_pid;
	int		recep;
}	t_global;

#endif