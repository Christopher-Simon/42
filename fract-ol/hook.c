/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/13 22:01:51 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

int	quit(t_data	*data)
{
		mlx_destroy_image(data->mlx.ptr, data->img.img);
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
		mlx_destroy_display(data->mlx.ptr);
		free(data->mlx.ptr);
		exit(0);
}

int	mouse(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	double	center_x;
	double	center_y;
	double	ecart_max;
	double	ecart_min;
	double	ecart_ajust_max;
	double	ecart_ajust_min;
	
	center_x = data->min_real - ((data->min_real - data->max_real)/2);
	center_y = data->min_imgr - ((data->min_imgr - data->max_imgr)/2);
	ecart_min = data->min_real - center_x;
	ecart_max = data->max_real - center_x;	
	if (keycode == 4)
	{
		ecart_ajust_max = ecart_max * 0.8;
		ecart_ajust_min = ecart_min * 0.8;
		data->min_imgr = center_y + ecart_ajust_min;
		data->max_imgr = center_y + ecart_ajust_max;
		data->min_real = center_x + ecart_ajust_min;
		data->max_real = center_x + ecart_ajust_max;
	}
	else if (keycode == 5)
	{
		ecart_ajust_max = ecart_max * 1.2;
		ecart_ajust_min = ecart_min * 1.2;
		data->min_imgr = center_y + ecart_ajust_min;
		data->max_imgr = center_y + ecart_ajust_max;
		data->min_real = center_x + ecart_ajust_min;
		data->max_real = center_x + ecart_ajust_max;
	}
	iniate(data);
	return (0);
}

void	small_mouv(int keycode, t_data *data)
{
	if (keycode == 'w')
	{
		data->min_imgr += 0.01;
		data->max_imgr += 0.01;
	}
	if (keycode == 'a')
	{
		data->min_real -= 0.01;
		data->max_real -= 0.01;
	}
	if (keycode == 's')
	{
		data->min_imgr -= 0.01;
		data->max_imgr -= 0.01;
	}
	if (keycode == 'd')
	{
		data->min_real += 0.01;
		data->max_real += 0.01;
	}
}

void	mouv(int keycode, t_data *data)
{
	if (keycode == 65362)
	{
		data->min_imgr += 0.05;
		data->max_imgr += 0.05;
	}
	if (keycode == 65361)
	{
		data->min_real -= 0.05;
		data->max_real -= 0.05;
	}
	if (keycode == 65364)
	{
		data->min_imgr -= 0.05;
		data->max_imgr -= 0.05;
	}
	if (keycode == 65363)
	{
		data->min_real += 0.05;
		data->max_real += 0.05;
	}
}

void param_julia(int keycode, t_data *data)
{
	if (keycode == 'h')
	{
		data->k_im += 0.005;
		data->k_im += 0.005;
	}
	if (keycode == 'j')
	{
		data->k_im -= 0.005;
		data->k_im -= 0.005;
	}
}

void param_color(int keycode, t_data *data)
{
	if (keycode - 48 > 0 && keycode - 48 < 10)
		data->color = keycode - 48;
}


int	zoom(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		quit(data);
		return (0);
	}
	mouv(keycode, data);
	small_mouv(keycode, data);
	param_julia(keycode, data);
	param_color(keycode, data);
	iniate(data);
	return(0);
}