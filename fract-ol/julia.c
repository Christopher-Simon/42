/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:47:51 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/11 18:34:36 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	julia(t_data *data, t_img *img)
{
	data->min_imgr = -2;
	data->max_imgr = 2;


	data->min_real = -2;
	data->max_real = 2;


	data->real_factor = (data->max_real - data->min_real) / (W_WIDTH - 1);
	data->imgr_factor = (data->max_imgr - data->min_imgr) / (W_HEIGHT - 1);
	// printf("data->real_factor: %f \n", data->real_factor);
	// printf("data->imgr_factor: %f \n", data->imgr_factor);

	int x = 0;
	int y = 0;
	int	count = 0;
	double c_re;
	double c_im;
	double z_re;
	double z_re_mem;
	double z_im;
	c_im = data->max_imgr - (y * data->imgr_factor);
	c_re = data->min_real + (x * data->real_factor);
	// printf("c_re : %f, c_im : %f\n", c_re, c_im);
	z_re_mem = 0;
	double	k_re = 0.370;
	double	k_im = 0.295;
	while (x < W_WIDTH)
	{
		c_re = data->min_real + (x * data->real_factor);
		y = 0;
		while (y < W_HEIGHT)
		{
			c_im = data->max_imgr - (y * data->imgr_factor);
			z_re = c_re;
			z_im = c_im;
			z_re_mem = 0;
			count = 0;
			while ((z_re*z_re + z_im + z_im < 4))
			{
				if (count == 20)
				{
					ft_mlx_pixel_put(img, x, y, 0x00FF0000);
					break;
				}
				z_re_mem = z_re * z_re - z_im * z_im + k_re;
				z_im = 2 * z_re * z_im + k_im;
				z_re = z_re_mem;
				count++;
			}
			y++;
		}
		x++;	
	}
}