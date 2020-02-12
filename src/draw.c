/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:22:43 by acarole           #+#    #+#             */
/*   Updated: 2020/02/12 20:47:39 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void	set_default(t_fdf *data)
{
	int x;
	int y;

	data->z = 1;
	data->angle = 0.82;
	x = 1500;
	y = 1000;
	data->shift_x = x / 2;
	data->shift_y = y / 3;
	data->zoom = 25;
	data->diff_iso = 1;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, x, y, "FdF");
	data->color_new = 0x0f6fa3;
	draw(data);
}

void	move(t_line *line, float *x_step, float *y_step, t_fdf *data)
{
	line->x += data->shift_x;
	line->y += data->shift_y;
	line->x1 += data->shift_x;
	line->y1 += data->shift_y;
	*x_step = line->x1 - line->x;
	*y_step = line->y1 - line->y;
}

void	bresenham(t_line line, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)line.y][(int)line.x];
	z1 = data->z_matrix[(int)line.y1][(int)line.x1];
	zoom(&line, data);
	check_iso(data, &z, &z1, &line);
	move(&line, &x_step, &y_step, data);
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(line.x - line.x1) || (int)(line.y - line.y1))
	{
		if (z1 || z)
			data->color = get_light(ft_color(data), 0xBBBBBB, 0.1);
		else
			data->color = ft_color(data);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, line.x,
		line.y, data->color);
		line.x += x_step;
		line.y += y_step;
	}
}

void	draw(t_fdf *data)
{
	t_line line;

	line.y = 0;
	print_menu(data);
	while (line.y < data->height)
	{
		line.x = 0;
		while (line.x < data->width)
		{
			if (line.x < data->width - 1)
			{
				line.x1 = line.x + 1;
				line.y1 = line.y;
				bresenham(line, data);
			}
			if (line.y < data->height - 1)
			{
				line.x1 = line.x;
				line.y1 = line.y + 1;
				bresenham(line, data);
			}
			line.x++;
		}
		line.y++;
	}
}
