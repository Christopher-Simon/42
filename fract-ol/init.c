/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 11:43:18 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/14 11:56:39 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == 0)
		exit (0);
	mlx->win = mlx_new_window(mlx->ptr, W_WIDTH, W_HEIGHT, "Hello, world!");
	if (!mlx->win)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit (0);
	}
}

int	quit(t_data	*data)
{
	mlx_destroy_image(data->mlx.ptr, data->img.img);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	mlx_destroy_display(data->mlx.ptr);
	free(data->mlx.ptr);
	exit(0);
}

void	init_img(t_img *img, t_mlx *mlx)
{
	img->img = mlx_new_image(mlx->ptr, W_WIDTH, W_HEIGHT);
	if (!img->img)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->e);
	if (!img->addr)
	{
		mlx_destroy_image(mlx->ptr, img->img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
		exit(0);
	}
}
