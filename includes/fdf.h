/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:11:05 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/13 16:09:35 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			shift_x;
	int			shift_y;
	float		angle;
	short int	diff_iso;
	int			z;
	float		color_new;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef	struct	s_line
{
	float x;
	float y;
	float x1;
	float y1;
}				t_line;

void			set_default(t_fdf *param);
void			read_file(char *file_name, t_fdf *data);
int				ft_wdcounter(char const *str, char c);
void			bresenham(t_line line, t_fdf *data);
void			draw(t_fdf *data);
void			check_input(int argc, char **argv);
void			print_menu(t_fdf *data);
void			ft_memdel1(char **mem);
void			ft_memdel3(int **mem);
int				ft_color(t_fdf *data);
int				get_light(int start, int end, double percentage);
void			isometric(float *x, float *y, int z, t_fdf *data);
void			check_iso(t_fdf *data, int *z, int *z1, t_line *line);
void			zoom(t_line *line, t_fdf *data);

#endif
