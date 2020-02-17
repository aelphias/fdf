/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:23:43 by acarole           #+#    #+#             */
/*   Updated: 2020/02/17 15:17:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(t_fdf *data)
{
	return (data->color_new);
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	check_iso(t_fdf *data, int *z, int *z1, t_line *line)
{
	*z *= data->z;
	*z1 *= data->z;
	if (data->diff_iso)
	{
		isometric(&line->x, &line->y, *z, data);
		isometric(&line->x1, &line->y1, *z1, data);
	}
	rotate_x(&line->x, *z, data);
	rotate_x(&line->x1, *z1, data);
	rotate_y(&line->y, *z, data);
	rotate_y(&line->y1, *z1, data);
	rotate_z(&line->x, &line->y, data);
	rotate_z(&line->x1, &line->y1, data);
}

void	zoom(t_line *line, t_fdf *data)
{
	line->x *= data->zoom;
	line->y *= data->zoom;
	line->x1 *= data->zoom;
	line->y1 *= data->zoom;
}
