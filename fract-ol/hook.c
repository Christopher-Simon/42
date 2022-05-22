/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/17 16:40:24 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

int	mouse(int keycode, int x, int y, t_data *data)
{
	double	center;
	double	ecart_ajust;
	double	cpl_x;
	double	cpl_y;

	center = data->min_real - ((data->min_real - data->max_real) / 2);
	cpl_x = data->min_real + (x * data->real_factor);
	cpl_y = data->max_imgr - (y * data->imgr_factor);
	if (keycode == 4)
		ecart_ajust = (data->max_real - center) * 0.8;
	else if (keycode == 5)
		ecart_ajust = (data->max_real - center) * 1.2;
	if (keycode == 5 || keycode == 4)
	{
		data->min_imgr = cpl_y - ecart_ajust;
		data->max_imgr = cpl_y + ecart_ajust;
		data->min_real = cpl_x - ecart_ajust;
		data->max_real = cpl_x + ecart_ajust;
	}
	iniate(data);
	return (0);
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

void	param_julia(int keycode, t_data *data)
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

void	param_color(int keycode, t_data *data)
{
	if (keycode - 48 > 0 && keycode - 48 < 10)
		data->color = keycode - 48;
	// printf("%d\n", data->color);
}

int	utils_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		quit(data);
		return (0);
	}
	if (keycode == 'p')
	{
		data->flag++;
		if (data->flag == 4)
			data->flag = 1;
		get_data(data);
		iniate(data);
	}
	mouv(keycode, data);
	param_julia(keycode, data);
	param_color(keycode, data);
	iniate(data);
	return (0);
}
