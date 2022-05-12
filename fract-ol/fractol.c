/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:13:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/12 17:14:28 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"


void	iniate(t_data *data)
{
	ft_bzero(data->img.addr, W_HEIGHT * W_WIDTH * (data->img.bits_per_pixel / 8));
	data->real_factor = (data->max_real - data->min_real) / (W_WIDTH - 1);
	data->imgr_factor = (data->max_imgr - data->min_imgr) / (W_HEIGHT - 1);
	if (data->flag == 1)
		mandel(data);
	else if (data->flag == 2)
		julia(data);
	else if (data->flag == 3)
		burning_ship(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
}



void	get_data(t_data *data)
{
	data->min_imgr = -2;
	data->max_imgr = 2;
	data->min_real = -2;
	data->max_real = 2;
	data->k_re = 0.370;
	data->k_im = 0.295;
}



void	fractol(int	flag)
{
	t_data	data;
	t_mlx	mlx;
	t_img	img;

	data.flag = flag;
	window(&mlx);
	data.mlx = mlx;
	img.img = mlx_new_image(mlx.ptr, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	data.img = img;
	get_data(&data);
	iniate(&data);

	mlx_hook(mlx.win, 17, 0, quit, &data);
	mlx_key_hook(mlx.win, zoom, &data);
	mlx_loop(mlx.ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Please choose between : \nmandelbrot\njulia\nburning_ship\n");
		return(0);
	}
	if (!ft_memcmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		fractol(1);
	else if (!ft_memcmp(argv[1], "julia", ft_strlen("julia")))
		fractol(2);
	else if (!ft_memcmp(argv[1], "burning_ship", ft_strlen("burning_ship")))
		fractol(3);
	else
	{
		printf("Please choose between : \nmandelbrot\njulia\nburning_ship\n");
		return(0);
	}
}
// destroy kill loop mlx bb (peut etre loop end mais c'est gus alors a voir)
// destroy img
// destroy window
// destroy mlx
//gcc -I/usr/include -Iminilibx-linux -Lminilibx-linux -c main.c -o main.o  -lmlx_Linux  -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz 