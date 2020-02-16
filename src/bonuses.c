/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:23:43 by acarole           #+#    #+#             */
/*   Updated: 2020/02/16 18:17:15 by acarole          ###   ########.fr       */
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

//  void	rotation(float *x, float *y, int z, t_fdf *data)
// {
// 	if(data->rotation_y)
// 		{
// 			*x = *x * cos(data->angle + data->rotation_y - 0.45) + z * sin(data->angle + data->rotation_y - 0.45);
// 			z = -*x * sin(data->angle + data->rotation_y - 0.45) + z * cos(data->angle + data->rotation_y - 0.45);
// 		}
// 		if(data->rotation_x)
// 		{
// 			*y = *y * cos(data->angle + data->rotation_x - 0.45) + z * sin(data->angle + data->rotation_x - 0.45);
// 			z = -*y * sin(data->angle + data->rotation_x - 0.45) + z * cos(data->angle + data->rotation_x - 0.45);
// 		}
// 		if(data->rotation_z)
// 		{
// 			*x = *x * cos(data->angle + data->rotation_z - 0.45) - *y * sin(data->angle + data->rotation_z - 0.45);
// 			*y = *x * sin(data->angle + data->rotation_z - 0.45) + *y * cos(data->angle + data->rotation_z - 0.45);
// 		}
// }

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

static void rotate_x(float *x, int z, t_fdf *data)
{	
		int     new_x;
        int     new_z;

		if(data->rotation_y)
		{
        	new_x = *x * cos(data->angle + data->rotation_y - 0.45) + z * -sin(data->angle + data->rotation_y - 0.45);
       		new_z = *x * sin(data->angle + data->rotation_y - 0.45) + z * cos(data->angle + data->rotation_y - 0.45);
       		*x = new_x;
        	z = new_z;
		}
}
static void rotate_y(float *y, int z, t_fdf *data)
{
		int     new_y;
        int     new_z;

		if(data->rotation_x)
       	{
			new_y = *y * cos(data->angle + data->rotation_x - 0.45) + z * sin(data->angle + data->rotation_x - 0.45);
     		new_z = *y * -sin(data->angle + data->rotation_x - 0.45) + z * cos(data->angle + data->rotation_x - 0.45);
        	*y = new_y;
       		z = new_z;
		}
}
static void rotate_z(float *x, float *y, t_fdf *data)
{
		int     new_x;
        int     new_y;
		if(data->rotation_z)
		{
       	 new_x = *x * cos(data->angle + data->rotation_z - 0.85) + *y * sin(data->angle + data->rotation_z - 0.85);
       	 new_y = *x * -sin(data->angle + data->rotation_z - 0.85) + *y * cos(data->angle + data->rotation_z - 0.85);
       	 *x = new_x;
       	 *y = new_y;
		}
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
	// rotation(&line->x, &line->y, *z, data);
	// rotation(&line->x1, &line->y1, *z1, data);
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
