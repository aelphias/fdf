/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:26:34 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/12 19:12:25 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_fdf *data)
{
	int		y;
	int		color;
	void	*mlx;
	void	*win;

	y = 0;
	color = 0xffffff;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, 65, y += 20, color, "How to Use");
	mlx_string_put(mlx, win, 15, y += 35, color, "Zoom: mouse wheel or + -");
	mlx_string_put(mlx, win, 15, y += 30, color, "Move: Arrows");
	mlx_string_put(mlx, win, 15, y += 30, color,
	"Flatten: numpad keys 8 and 2");
	mlx_string_put(mlx, win, 15, y += 30, color, "Switch projection: keys [ ]");
	mlx_string_put(mlx, win, 15, y += 30, color, "Change colors Z and X");
	mlx_string_put(mlx, win, 57, y += 25, color, "");
	mlx_string_put(mlx, win, 57, y += 25, color, "");
	mlx_string_put(mlx, win, 57, y += 25, color, "");
	mlx_string_put(mlx, win, 15, y += 30, color, "");
	mlx_string_put(mlx, win, 57, y += 25, color, "");
	mlx_string_put(mlx, win, 57, y += 25, color, "");
}
