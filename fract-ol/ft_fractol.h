/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:17:43 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/14 12:49:06 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define W_HEIGHT 1000
# define W_WIDTH 1000

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		e;
}	t_img;

typedef struct s_data
{
	int		flag;
	int		color;
	double	min_imgr;
	double	max_imgr;
	double	min_real;
	double	max_real;
	double	real_factor;
	double	imgr_factor;
	double	c_re;
	double	c_im;	
	double	k_re;
	double	k_im;
	double	z_re;
	double	z_re_mem;
	double	z_im;
	t_mlx	mlx;
	t_img	img;
}	t_data;

void	number_cruncher(t_data *data, void (*equation)(t_data *data));
void	mandel_equation(t_data *data);
void	burning_ship_equation(t_data *data);
void	julia_equation(t_data *data);
void	iniate(t_data *data);
void	get_data(t_data *data);
void	get_cpl(t_data *data, int y);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
int		utils_hook(int keycode, t_data *data);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(void *s1, void *s2, size_t n);
size_t	ft_strlen(const char *s);
int		trans(int keycode, t_data *data);
void	window(t_mlx *mlx);
int		mouse(int keycode, int x, int y, t_data *data);
int		color(int count, t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		quit(t_data	*data);
void	init_img(t_img *img, t_mlx *mlx);
void	init_values(t_data *data, t_pos *pos);

#endif