/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:17:43 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/11 19:17:25 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define W_HEIGHT 1000
# define W_WIDTH 1000

typedef	struct	s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data 
{
	double	min_imgr;
	double	max_imgr;
	double	min_real;
	double	max_real;
	double	real_factor;
	double	imgr_factor;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_re_mem;
	double	z_im;
	t_mlx	mlx;
	t_img	img;
}	t_data;

void	mandel(t_data *data);
void	burning_ship(t_data *data, t_img *img);
void	julia(t_data *data, t_img *img);
void	iniate(t_data *data);
void	ft_mlx_pixel_put(t_img *data, int x, int y, int color);
int		zoom(int keycode, t_data *data);
void	ft_bzero(void *s, size_t n);
int		trans(int keycode, t_data *data);
void	window(t_mlx *mlx);

#endif