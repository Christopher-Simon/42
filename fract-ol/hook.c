/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/12 19:15:48 by chsimon          ###   ########.fr       */
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

int	mouse(int keycode, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		data->min_imgr *= 0.8;
		data->max_imgr *= 0.8;
		data->min_real *= 0.8;
		data->max_real *= 0.8;
	}
	if (keycode == 4)
	{
		data->min_imgr *= 1.2;
		data->max_imgr *= 1.2;
		data->min_real *= 1.2;
		data->max_real *= 1.2;
	}
	iniate(data);
	return (0);
}

int	zoom(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		quit(data);
		return (0);
	}
	if (keycode == 'o')
	{
		data->min_imgr *= 0.8;
		data->max_imgr *= 0.8;
		data->min_real *= 0.8;
		data->max_real *= 0.8;
	}
	if (keycode == 'p')
	{
		data->min_imgr *= 1.2;
		data->max_imgr *= 1.2;
		data->min_real *= 1.2;
		data->max_real *= 1.2;
	}
	if (keycode == 'w')
	{
		data->min_imgr += 0.05;
		data->max_imgr += 0.05;
	}
	if (keycode == 'a')
	{
		data->min_real -= 0.05;
		data->max_real -= 0.05;
	}
	if (keycode == 's')
	{
		data->min_imgr -= 0.05;
		data->max_imgr -= 0.05;
	}
	if (keycode == 'd')
	{
		data->min_real += 0.05;
		data->max_real += 0.05;
	}
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
	iniate(data);
	return(0);
}