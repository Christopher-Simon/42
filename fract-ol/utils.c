/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:37:11 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/12 15:39:36 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n--)
		*((unsigned char *)s + i++) = '\0';
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n--)
	{
		if ((*((unsigned char *)s1 + i)) != (*((unsigned char *)s2 + i)))
		{
			return ((*((unsigned char *)s1 + i))
				- (*((unsigned char *)s2 + i)));
		}
		i++;
	}
	return (0);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, W_WIDTH, W_HEIGHT, "Hello, world!");;
}

