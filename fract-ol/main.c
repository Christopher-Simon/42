#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data *img, int color)
{
	int	line;
	int	column;
	(void)color;

	line = 100;
	column = 100;
	while (line < 495)
	{
		column = 100;
		while (column < 495)
		{
			ft_mlx_pixel_put(img, line, column, 0x00FF0000);
			column++;
		}
		line++;
	}

}

void	losange(t_data *img, int color)
{
	int	height;
	int	center_col;
	int	center_line;
	int	x;

	(void)color;
	height = 100;
	center_col = 250;
	center_line = 250;
	x = 0;
	while ((height--))
	{
		ft_mlx_pixel_put(img, center_line + x, center_col - (height),0x00FF0000);
		ft_mlx_pixel_put(img, center_line - x, center_col + (height),0x00FF0000);
		ft_mlx_pixel_put(img, center_line + height, center_col + (x),0x00FF0000);
		ft_mlx_pixel_put(img, center_line - height, center_col - (x),0x00FF0000);
		x++;
	}
}

// int	c_value(int x, int y)
// {

// }

// int	is_mandel(double c)
// {
// 	int x;
// 	double z;

// 	z = 0;
// 	x = 0;
// 	while (x++ < 100 && z != INFINITY)
// 	{
// 		z = z*z + c;
// 		printf("%d : %f\n",x, z);
// 	}
// 	return (1);
// }

void	window(t_mlx *mlx)
{
	mlx->win_height = 400;
	mlx->win_width = 400;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->win_width, mlx->win_height, "Hello, world!");;
}

void	scale(t_mlx *mlx, t_plane *plane)
{
	plane->min_imgr = -2;
	plane->max_imgr = 2;


	plane->min_real = -2;
	plane->max_real = 2;


	plane->real_factor = (plane->max_real - plane->min_real) / mlx->win_width;
	plane->imgr_factor = (plane->max_imgr - plane->min_imgr) / mlx->win_height;
	printf("plane->real_factor: %f \n", plane->real_factor);
	printf("plane->imgr_factor: %f \n", plane->imgr_factor);


	//test avec x et y
	int x = 300;
	int y = 300;
	double c_re;
	double c_im;
	c_re = plane->min_real + (x * plane->real_factor);
	c_im = plane->max_imgr - (y * plane->imgr_factor);
	printf("(x plane, y plane)\n(%f, %f)", c_re, c_im);
}


int	main(void)
{
	t_data	img;
	t_mlx	mlx;
	t_plane	plane;

	window(&mlx);
	img.img = mlx_new_image(mlx.ptr, mlx.win_width, mlx.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_mlx_pixel_put(&img, 100, 300, 0x00FF0000);
	scale(&mlx, &plane);

	// mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	// mlx_loop(mlx.ptr);
	// is_mandel(1);
}

//gcc -I/usr/include -Iminilibx-linux -Lminilibx-linux -c main.c -o main.o  -lmlx_Linux  -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz 