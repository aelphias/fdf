/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:59:41 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/03 17:30:31 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    printf("{ 1 }\n");
    fdf *data;
    int i;
    int j;

    i = 0;
    if (argc != 2)
        return(1);
    printf("{ 2 }");
    data = (fdf*)malloc(sizeof(fdf));
    read_file(argv[1], data);
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            printf("%3d", data->z_matrix[i][j]);
            j++;
        }
        i++;   
    }
    return(0);
}