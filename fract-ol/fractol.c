#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

int	close(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->ptr, mlx->win);
	return (0);
}

int	red_cross_close(t_mlx *mlx)
{
	// mlx_destroy_image
	mlx_destroy_window(mlx->ptr, mlx->win);
	return (0);
}



void	iniate(t_data *data)
{
	ft_bzero(data->img.addr, W_HEIGHT * W_WIDTH * (data->img.bits_per_pixel / 8));
	data->real_factor = (data->max_real - data->min_real) / (W_WIDTH - 1);
	data->imgr_factor = (data->max_imgr - data->min_imgr) / (W_HEIGHT - 1);
	mandel(data);
	// julia(data);
	// burning_ship(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.img, 0, 0);
}



void	get_data(t_data *data)
{
	data->min_imgr = -2;
	data->max_imgr = 2;
	data->min_real = -2;
	data->max_real = 2;
}



void	fractol(void)
{
	t_data	data;
	t_mlx	mlx;
	t_img	img;

	window(&mlx);
	data.mlx = mlx;
	img.img = mlx_new_image(mlx.ptr, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	data.img = img;
	// int flag = 1;
	get_data(&data);
	iniate(&data);

	mlx_key_hook(mlx.win, close, &mlx);
	mlx_hook(mlx.win, 17, 0, red_cross_close, &mlx);
	printf("%f\n", data.min_imgr);
	mlx_key_hook(mlx.win, zoom, &data);

	mlx_loop(mlx.ptr);
}

int	main(void)
{
	fractol();
}
// destroy kill loop mlx bb (peut etre loop end mais c'est gus alors a voir)
// destroy img
// destroy window
// destroy mlx
//gcc -I/usr/include -Iminilibx-linux -Lminilibx-linux -c main.c -o main.o  -lmlx_Linux  -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz 