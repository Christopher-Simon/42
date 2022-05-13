/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:47:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/13 22:06:52 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"



void	julia(t_data *data)
{


	int x = 0;
	int y = 0;
	int	count = 0;
	data->z_re_mem = 0;	
	while (x < W_WIDTH)
	{
		data->c_re = data->min_real + (x * data->real_factor);
		y = 0;
		while (y < W_HEIGHT)
		{
			data->c_im = data->max_imgr - (y * data->imgr_factor);
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			data->z_re_mem = 0;
			count = 0;
			while ((data->z_re*data->z_re + data->z_im + data->z_im < 4))
			{
				if (count == 150)
				{
					ft_mlx_pixel_put(&data->img, x, y, 0x00000000);
					break;
				}
				data->z_re_mem = data->z_re * data->z_re - data->z_im * data->z_im + data->k_re;
				data->z_im = 2 * data->z_re * data->z_im + data->k_im;
				data->z_re = data->z_re_mem;
				count++;
			}
			if (count < 150)
				ft_mlx_pixel_put(&data->img, x, y, color(count, data));
			y++;
		}
		x++;	
	}
}