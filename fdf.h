/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:47:05 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/04 15:34:06 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>           /*`REMOVE AFTER DEBUG`*/
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct 
{
    int     width;
    int     height;
    int     **a_matrix;

    void    *mlx_ptr;
    void    *win_ptr;
}              fdf;

void    read_file(char *filename, fdf *data);

#endif
