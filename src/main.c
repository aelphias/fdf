/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:23:23 by acarole           #+#    #+#             */
/*   Updated: 2020/02/12 22:38:24 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_exit(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int		deal_mouse(int mouse, int x, int y, t_fdf *data)
{
	if (x >= 0 && y >= 0)
	{
		if (mouse == 5)
			data->zoom += 1;
		if (mouse == 4)
			data->zoom -= 1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}

void	deal_key_move(int key, t_fdf *data)
{
	if (key == 86)
		data->angle += 0.04;
	if (key == 88)
		data->angle -= 0.04;
	if (key == 126)
		data->shift_y -= 15;
	if (key == 125)
		data->shift_y += 15;
	if (key == 123)
		data->shift_x -= 15;
	if (key == 124)
		data->shift_x += 15;
}

int		deal_key(int key, t_fdf *data)
{
	if (key == 6)
		data->color_new *= 1.3;
	if (key == 7)
		data->color_new /= 1.3;
	if (key == 91)
		data->z += 1;
	if (key == 84)
		data->z -= 1;
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 33)
		data->diff_iso = 0;
	if (key == 30)
		data->diff_iso = 1;
	if (key == 53)
		exit(0);
	deal_key_move(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf *data;

	check_input(argc, argv);
	data = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	read_file(argv[1], data);
	set_default(data);
	mlx_mouse_hook(data->win_ptr, deal_mouse, data);
	mlx_hook(data->win_ptr, 2, 0, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
	if (data)
		free(data);
	return (0);
}
