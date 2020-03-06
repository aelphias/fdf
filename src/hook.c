/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:10:04 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/17 22:34:30 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_mouse(int mouse, int x, int y, t_fdf *data)
{
	if (x >= 0 && y >= 0)
	{
		if (mouse == 5 && (data->zoom < 260))
		{
			data->zoom += 2;
			if (data->zoom > 90 && (data->zoom < 260))
				data->zoom *= 1.02;
		}
		if (mouse == 4 && (data->zoom > 5))
		{
			if (data->zoom > 90 && (data->zoom < 260))
				data->zoom /= 1.02;
			data->zoom -= 2;
		}
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}

void	deal_key_move(int key, t_fdf *data)
{
	if (key == 13)
		data->rotation_x += 0.1;
	if (key == 1)
		data->rotation_x -= 0.1;
	if (key == 0)
		data->rotation_y += 0.1;
	if (key == 2)
		data->rotation_y -= 0.1;
	if (key == 86)
		data->rotation_z += 0.1;
	if (key == 88)
		data->rotation_z -= 0.1;
	if (key == 126)
		data->shift_y -= 15;
	if (key == 125)
		data->shift_y += 15;
	if (key == 123)
		data->shift_x -= 15;
	if (key == 124)
		data->shift_x += 15;
}

void	deal_iso(int key, t_fdf *data)
{
	if (key == 33)
	{
		data->rotation_y = 0;
		data->rotation_x = 0;
		data->rotation_z = 0;
		data->diff_iso = 0;
		data->shift_x = 670;
		data->shift_y = 333;
	}
	if (key == 30)
	{
		data->rotation_y = 0;
		data->rotation_x = 0;
		data->rotation_z = 0;
		data->diff_iso = 1;
		data->shift_x = 670;
		data->shift_y = 333;
	}
}

void	deal_key1(int key, t_fdf *data)
{
	if (key == 69 && (data->zoom < 260))
	{
		data->zoom += 2;
		if (data->zoom > 90 && (data->zoom < 260))
			data->zoom *= 1.02;
	}
	if (key == 78 && (data->zoom > 5))
	{
		if (data->zoom > 90 && (data->zoom < 260))
			data->zoom /= 1.02;
		data->zoom -= 2;
	}
	if (key == 53)
		exit(0);
}

int		deal_key(int key, t_fdf *data)
{
	if (key == 6)
		data->color_new *= 1.3;
	if (key == 7)
		data->color_new /= 1.3;
	if (key == 91)
	{
		if (data->z == -1)
			data->z++;
		data->z += 1;
	}
	if (key == 84)
	{
		if (data->z == 1)
			data->z--;
		data->z -= 1;
	}
	deal_iso(key, data);
	deal_key1(key, data);
	deal_key_move(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}
