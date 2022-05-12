/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:28:20 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/12 15:59:29 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

int	mandel_color(int count)
{
	if (count < 5)
		return(0x00000000);
	else if (count < 10)
		return(0x000000FF);
	else if (count < 15)
		return(0x0000FF00);
	else
		return(0x00FFFFFF);
}

void	mandel(t_data *data)
{
	int x = 0;
	int y = 0;
	int	count = 0;

	// data->c_im = data->max_imgr - (y * data->imgr_factor);
	// data->c_re = data->min_real + (x * data->real_factor);
	// printf("data->c_re : %f, data->c_im : %f\n", data->c_re, data->c_im);
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
				if (count == 20)
				{
					ft_mlx_pixel_put(&data->img, x, y, 0x00FF0000);
					break;
				}
				data->z_re_mem = data->z_re * data->z_re - data->z_im * data->z_im + data->c_re;
				data->z_im = 2 * data->z_re * data->z_im + data->c_im;
				data->z_re = data->z_re_mem;
				count++;
			}
			if (count < 20)
				ft_mlx_pixel_put(&data->img, x, y, mandel_color(count));
			y++;
		}
		x++;	
	}
}