/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cruncher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:28:20 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/14 12:49:55 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	mandel_equation(t_data *data)
{
	data->z_re_mem = data->z_re * data->z_re
		- data->z_im * data->z_im + data->c_re;
	data->z_im = 2 * data->z_re * data->z_im + data->c_im;
	data->z_re = data->z_re_mem;
}

void	burning_ship_equation(t_data *data)
{
	data->z_re_mem = data->z_re * data->z_re
		- data->z_im * data->z_im + data->c_re;
	data->z_im = fabs(2 * data->z_re * data->z_im) + data->c_im;
	data->z_re = data->z_re_mem;
}

void	julia_equation(t_data *data)
{
	data->z_re_mem = data->z_re * data->z_re
		- data->z_im * data->z_im + data->k_re;
	data->z_im = 2 * data->z_re * data->z_im + data->k_im;
	data->z_re = data->z_re_mem;
}

void	calculation_loop(t_data *data, t_pos *pos,
	int count, void (*equation)(t_data *data))
{
	while ((data->z_re * data->z_re + data->z_im + data->z_im < 4))
	{
		if (count == 250)
		{
			ft_mlx_pixel_put(&data->img, pos->x, pos->y, 0x00000000);
			break ;
		}
		equation(data);
		count++;
	}
	if (count < 250)
		ft_mlx_pixel_put(&data->img, pos->x, pos->y, color(count, data));
}

void	number_cruncher(t_data *data, void (*equation)(t_data *data))
{
	t_pos	pos;

	init_values(data, &pos);
	while (pos.x < W_WIDTH)
	{
		data->c_re = data->min_real + (pos.x * data->real_factor);
		pos.y = 0;
		while (pos.y < W_HEIGHT)
		{
			get_cpl(data, pos.y);
			calculation_loop(data, &pos, 0, equation);
			pos.y++;
		}
		pos.x++;
	}
}
