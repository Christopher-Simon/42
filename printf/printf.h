/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:59:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/01/12 19:10:02 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	_PRINTF_H_
# define _PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_flags
{
	int	size;
	int	width;
	int	prec;
	int	nb_size;
} t_flags;


int		ft_printf(const char *s, ...);
int		find_nb_size(int n);
int		find_prec(const char *s);
int		find_width(const char *s);
int		max_size(int w, int p, int n);

#endif
