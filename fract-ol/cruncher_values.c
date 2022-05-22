/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cruncher_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:56:28 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/14 12:46:05 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	init_values(t_data *data, t_pos *pos)
{
	pos->x = 0;
	pos->y = 0;
	data->z_re_mem = 0;
}

void	get_cpl(t_data *data, int y)
{
	data->c_im = data->max_imgr - (y * data->imgr_factor);
	data->z_re = data->c_re;
	data->z_im = data->c_im;
	data->z_re_mem = 0;
}
