/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:43:41 by chsimon           #+#    #+#             */
/*   Updated: 2022/05/14 12:00:29 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "ft_fractol.h"

int	color_2(int count)
{
	if (count < 5)
		return (0x00FFFFFF);
	else if (count < 10)
		return (0x000000FF);
	else if (count < 15)
		return (0x0000FF00);
	else
		return (0x00FFFFFF);
}

int	julia_color(int count)
{
	if (count < 50)
		return (0x00FFFFFF);
	else if (count < 100)
		return (0x000000FF);
	else if (count < 150)
		return (0x0000FF00);
	else
		return (0x00FFFFFF);
}

int	b_ship_color(int count)
{
	if (count < 100)
		return (0x00280000);
	if (count < 150)
		return (0x00480000);
	else if (count < 200)
		return (0x00680000);
	else if (count < 225)
		return (0x00C00000);
	else
		return (0x00FFFF00);
}

int	color_1(int count)
{
	if (count < 50)
		return (create_trgb(255, 255, 100, 0));
	else if (count < 125)
		return (create_trgb(255, 255, 150, 0));
	else if (count < 175)
		return (create_trgb(255, 255, 200, 0));
	else
		return (create_trgb(255, 255, 250, 0));
}

int	color(int count, t_data *data)
{
	if (data->color == 1)
		return (create_trgb(255, 255, (int)log(count) * 100, 0));
	else if (data->color == 2)
		return (create_trgb(255, 255, (255 - count), 0));
	else if (data->color == 3)
		return (b_ship_color(count));
	else if (data->color == 4)
		return (julia_color(count));
	else if (data->color == 5)
		return (color_2(count));
	else if (data->color == 6)
		return (color_1(count));
	else
	{
		data->color = 1;
		color(count, data);
	}
	return (0);
}
