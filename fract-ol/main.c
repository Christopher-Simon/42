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

losange(t_data *img, int color)
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

void fx(int x, t_data *img)
{
	int y;

	y = 200;
	while (x < 200)
	{
		mlx_pixel_put(mlx, mlx_win, 200, 200, 0x00FF0000);
		ft_mlx_pixel_put(img, x, y, 0x00FF0000);
		y++;
		x++;
	}
}

// void	ft_drawline(int x1, int x2, int y1, int y2)
// {
	
// 	while (x1 < x2)
// 	{
// 		ft_mlx_pixel_put(img, )
// 	}
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 495, 495, "Hello, world!");
	img.img = mlx_new_image(mlx, 495, 495);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// losange(&img, 0x00FF0000);
	fx(0, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
