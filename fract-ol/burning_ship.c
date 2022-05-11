/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:31:03 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/11 23:38:40 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"


int	b_ship_color(int count)
{
	if (count < 10)
		return(0x00280000);
	if (count < 15)
		return(0x00480000);
	else if (count < 25)
		return(0x00680000);
	else if (count < 50)
		return(0x00C00000);
	else
		return(0x00FFFF00);
}

void	burning_ship(t_data *data)
{
	// printf("data->real_factor: %f \n", data->real_factor);
	// printf("data->imgr_factor: %f \n", data->imgr_factor);


	//test avec x et y
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
				if (count == 255)
				{
					ft_mlx_pixel_put(&data->img, x, y, 0x00000000);
					break;
				}
				z_re_mem = z_re * z_re - z_im * z_im + c_re;
				z_im = fabs(2 * z_re * z_im) + c_im;
				z_re = z_re_mem;
				count++;
			}
			if (count < 255)
				ft_mlx_pixel_put(&data->img, x, y, b_ship_color(count));
			y++;
		}
		x++;	
	}
	

	
	// printf("(x data, y data)\n(%f, %f)", c_re, c_im);
}