/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:13:04 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/19 18:15:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (!write(fd, s, ft_strlen(s)))
		return ;
}

void	iniate(t_data *data)
{
	ft_bzero(data->img.addr, W_HEIGHT * W_WIDTH
		* (data->img.bpp / 8));
	data->real_factor = (data->max_real - data->min_real) / (W_WIDTH - 1);
	data->imgr_factor = (data->max_imgr - data->min_imgr) / (W_HEIGHT - 1);
	if (data->flag == 1)
		number_cruncher(data, &mandel_equation);
	if (data->flag == 2)
		number_cruncher(data, &julia_equation);
	if (data->flag == 3)
		number_cruncher(data, &burning_ship_equation);
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
	data->color = 1;
}

void	fractol(int flag)
{
	t_data	data;
	t_mlx	mlx;
	t_img	img;

	ft_putstr_fd("Change between fractals with P\nColors with C\n", 1);
	ft_putstr_fd("Move with the arrows\n", 1);
	ft_putstr_fd("For Julia, change param with H & J\n", 1);
	window(&mlx);
	init_img(&img, &mlx);
	data.flag = flag;
	data.mlx = mlx;
	data.img = img;
	get_data(&data);
	iniate(&data);
	mlx_key_hook(mlx.win, utils_hook, &data);
	mlx_mouse_hook(mlx.win, mouse, &data);
	mlx_hook(mlx.win, 17, 0, quit, &data);
	mlx_loop(mlx.ptr);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Please choose between : \n", 1);
		ft_putstr_fd("mandelbrot\njulia\nburning_ship\n", 1);
		return (0);
	}
	if (!ft_memcmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")))
		fractol(1);
	else if (!ft_memcmp(argv[1], "julia", ft_strlen("julia")))
		fractol(2);
	else if (!ft_memcmp(argv[1], "burning_ship", ft_strlen("burning_ship")))
		fractol(3);
	else
	{
		ft_putstr_fd("Please choose between : \n", 1);
		ft_putstr_fd("mandelbrot\njulia\nburning_ship\n", 1);
		return (0);
	}
}
