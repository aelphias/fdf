/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:23:23 by acarole           #+#    #+#             */
/*   Updated: 2020/02/16 22:07:04 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
