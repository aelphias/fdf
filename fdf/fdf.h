/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:04:14 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/03 16:41:51 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include  <stdio.h> /* REMOVE AFTER DEBUG*/

typedef struct
{
    int height;
    int width;
    int **z_matrix;

    void	**mlx_ptr;
    void	**win_ptr;
}				fdf;

void    read_file(char *file_name, fdf *data);

#endif
