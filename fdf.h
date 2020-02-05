/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:47:05 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/05 19:57:37 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>           /*`REMOVE AFTER DEBUG`*/
#include <math.h>   
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include "minilibx_macos/mlx.h"

typedef struct 
{
    int     width;
    int     height;
    int     **a_matrix;
    int     zoom;
    int     color;
    int     shift_x;
    int     shift_y;

    void    *mlx_ptr;
    void    *win_ptr;
}              fdf;

void    read_file(char *filename, fdf *data);
void    bresenham(float x, float y, float x1, float y1, fdf *data);
void    draw(fdf *data);

#endif
