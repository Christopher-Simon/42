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