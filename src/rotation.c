/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:14:49 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/17 16:06:08 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *x, int z, t_fdf *data)
{
	int	new_x;
	int	new_z;

	if (data->rotation_y)
	{
		new_x = *x * cos(data->angle + data->rotation_y - 0.45)
		+ z * -sin(data->angle + data->rotation_y - 0.45);
		new_z = *x * sin(data->angle + data->rotation_y - 0.45)
		+ z * cos(data->angle + data->rotation_y - 0.45);
		*x = new_x;
		z = new_z;
	}
}

void	rotate_y(float *y, int z, t_fdf *data)
{
	int	new_y;
	int	new_z;

	if (data->rotation_x)
	{
		new_y = *y * cos(data->angle + data->rotation_x - 0.45)
		+ z * sin(data->angle + data->rotation_x - 0.45);
		new_z = *y * -sin(data->angle + data->rotation_x - 0.45)
		+ z * cos(data->angle + data->rotation_x - 0.45);
		*y = new_y;
		z = new_z;
	}
}

void	rotate_z(float *x, float *y, t_fdf *data)
{
	int	new_x;
	int	new_y;

	if (data->rotation_z)
	{
		new_x = *x * cos(data->angle + data->rotation_z - 0.85)
		+ *y * sin(data->angle + data->rotation_z - 0.85);
		new_y = *x * -sin(data->angle + data->rotation_z - 0.85)
		+ *y * cos(data->angle + data->rotation_z - 0.85);
		*x = new_x;
		*y = new_y;
	}
}
