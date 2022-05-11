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
	mlx->win_height = 1000;
	mlx->win_width = 1000;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, mlx->win_width, mlx->win_height, "Hello, world!");;
}

void	julia(t_mlx *mlx, t_plane *plane, t_data *img)
{
	plane->min_imgr = -2;
	plane->max_imgr = 2;


	plane->min_real = -2;
	plane->max_real = 2;


	plane->real_factor = (plane->max_real - plane->min_real) / (mlx->win_width - 1);
	plane->imgr_factor = (plane->max_imgr - plane->min_imgr) / (mlx->win_height - 1);
	printf("plane->real_factor: %f \n", plane->real_factor);
	printf("plane->imgr_factor: %f \n", plane->imgr_factor);


	//test avec x et y
	int x = 0;
	int y = 0;
	int	count = 0;
	double c_re;
	double c_im;
	double z_re;
	double z_re_mem;
	double z_im;

	c_im = plane->max_imgr - (y * plane->imgr_factor);
	c_re = plane->min_real + (x * plane->real_factor);
	printf("c_re : %f, c_im : %f\n", c_re, c_im);
	z_re_mem = 0;
	double	k_re = 0.353;
	double	k_im = 0.288;

	
	while (x < mlx->win_width)
	{
		c_re = plane->min_real + (x * plane->real_factor);
		y = 0;
		while (y < mlx->win_height)
		{
			c_im = plane->max_imgr - (y * plane->imgr_factor);
			z_re = c_re;
			z_im = c_im;
			z_re_mem = 0;
			count = 0;
			while ((z_re*z_re + z_im + z_im < 4))
			{
				if (count == 20)
				{
					ft_mlx_pixel_put(img, x, y, 0x00FF0000);
					break;
				}
				z_re_mem = z_re * z_re - z_im * z_im + k_re;
				z_im = 2 * z_re * z_im + k_im;
				z_re = z_re_mem;
				count++;
			}
			y++;
		}
		x++;	
	}
	

	
	// printf("(x plane, y plane)\n(%f, %f)", c_re, c_im);
}

void	mandel(t_mlx *mlx, t_plane *plane, t_data *img)
{
	plane->min_imgr = -2;
	plane->max_imgr = 2;


	plane->min_real = -2;
	plane->max_real = 2;


	plane->real_factor = (plane->max_real - plane->min_real) / (mlx->win_width - 1);
	plane->imgr_factor = (plane->max_imgr - plane->min_imgr) / (mlx->win_height - 1);
	printf("plane->real_factor: %f \n", plane->real_factor);
	printf("plane->imgr_factor: %f \n", plane->imgr_factor);


	//test avec x et y
	int x = 0;
	int y = 0;
	int	count = 0;
	double c_re;
	double c_im;
	double z_re;
	double z_re_mem;
	double z_im;

	c_im = plane->max_imgr - (y * plane->imgr_factor);
	c_re = plane->min_real + (x * plane->real_factor);
	printf("c_re : %f, c_im : %f\n", c_re, c_im);
	z_re_mem = 0;
	// while ((z_re*z_re + z_im + z_im < 4))
	// {
	// 	if (count == 20)
	// 	{
	// 		ft_mlx_pixel_put(img, x, y, 0x00FF0000);
	// 		printf("it's in");
	// 		break;
	// 	}
	// 	z_re_mem = z_re * z_re - z_im * z_im + c_re;
	// 	z_im = 2 * z_re * z_im + c_im;
	// 	z_re = z_re_mem;
	// 	count++;
	// }

	
	while (x < mlx->win_width)
	{
		c_re = plane->min_real + (x * plane->real_factor);
		y = 0;
		while (y < mlx->win_height)
		{
			c_im = plane->max_imgr - (y * plane->imgr_factor);
			z_re = c_re;
			z_im = c_im;
			z_re_mem = 0;
			count = 0;
			while ((z_re*z_re + z_im + z_im < 4))
			{
				if (count == 20)
				{
					ft_mlx_pixel_put(img, x, y, 0x00FF0000);
					break;
				}
				z_re_mem = z_re * z_re - z_im * z_im + c_re;
				z_im = 2 * z_re * z_im + c_im;
				z_re = z_re_mem;
				count++;
			}
			y++;
		}
		x++;	
	}
	

	
	// printf("(x plane, y plane)\n(%f, %f)", c_re, c_im);
}

void	burning_ship(t_mlx *mlx, t_plane *plane, t_data *img)
{
	plane->min_imgr = -1.5;
	plane->max_imgr = -0.5;


	plane->min_real = -1.5;
	plane->max_real = -0.5;


	plane->real_factor = (plane->max_real - plane->min_real) / (mlx->win_width - 1);
	plane->imgr_factor = (plane->max_imgr - plane->min_imgr) / (mlx->win_height - 1);
	printf("plane->real_factor: %f \n", plane->real_factor);
	printf("plane->imgr_factor: %f \n", plane->imgr_factor);


	//test avec x et y
	int x = 0;
	int y = 0;
	int	count = 0;
	double c_re;
	double c_im;
	double z_re;
	double z_re_mem;
	double z_im;

	c_im = plane->max_imgr - (y * plane->imgr_factor);
	c_re = plane->min_real + (x * plane->real_factor);
	printf("c_re : %f, c_im : %f\n", c_re, c_im);
	z_re_mem = 0;
	
	while (x < mlx->win_width)
	{
		c_re = plane->min_real + (x * plane->real_factor);
		y = 0;
		while (y < mlx->win_height)
		{
			c_im = plane->max_imgr - (y * plane->imgr_factor);
			z_re = c_re;
			z_im = c_im;
			z_re_mem = 0;
			count = 0;
			while ((z_re*z_re + z_im + z_im < 4))
			{
				if (count == 100)
				{
					ft_mlx_pixel_put(img, x, y, 0x00FF0000);
					break;
				}
				z_re_mem = z_re * z_re - z_im * z_im + c_re;
				z_im = fabs(2 * z_re * z_im) + c_im;
				z_re = z_re_mem;
				count++;
			}
			y++;
		}
		x++;	
	}
	

	
	// printf("(x plane, y plane)\n(%f, %f)", c_re, c_im);
}

int	main(void)
{
	t_data	img;
	t_mlx	mlx;
	t_plane	plane;

	window(&mlx);
	img.img = mlx_new_image(mlx.ptr, mlx.win_width, mlx.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// ft_mlx_pixel_put(&img, 100, 300, 0x00FF0000);
	burning_ship(&mlx, &plane, &img);

	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.ptr);
	// is_mandel(1);
}

//gcc -I/usr/include -Iminilibx-linux -Lminilibx-linux -c main.c -o main.o  -lmlx_Linux  -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz 