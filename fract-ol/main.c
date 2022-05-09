#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>

typedef struct s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 495, 495, "Hello, world!");
	img.img = mlx_new_image(mlx, 495, 495);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	losange(&img, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

//gcc -I/usr/include -Iminilibx-linux -Lminilibx-linux -c main.c -o main.o  -lmlx_Linux  -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz 