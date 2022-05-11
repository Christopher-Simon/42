/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:37:11 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/11 19:19:49 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*((unsigned char *)s + i++) = '\0';
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, W_WIDTH, W_HEIGHT, "Hello, world!");;
}

int	zoom(int keycode, t_data *data)
{
	if (keycode == 'o')
	{
		data->min_imgr += 0.05;
		data->max_imgr -= 0.05;
		data->min_real += 0.05;
		data->max_real -= 0.05;
	}
	if (keycode == 'p')
	{
		data->min_imgr -= 0.05;
		data->max_imgr += 0.05;
		data->min_real -= 0.05;
		data->max_real += 0.05;
	}
	if (keycode == 'w')
	{
		data->min_imgr += 0.02;
		data->max_imgr += 0.02;
	}
	if (keycode == 'a')
	{
		data->min_real -= 0.02;
		data->max_real -= 0.02;
	}
	if (keycode == 's')
	{
		data->min_imgr -= 0.02;
		data->max_imgr -= 0.02;
	}
	if (keycode == 'd')
	{
		data->min_real += 0.02;
		data->max_real += 0.02;
	}
	iniate(data);
	return(0);
}
