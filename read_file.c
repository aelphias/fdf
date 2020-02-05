/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:46:35 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/05 19:48:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fill_matrix(int *a_line, char *line)
{
    char **nums;
    int i;

    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
      a_line[i] = ft_atoi(nums[i]);
      free(nums[i]);
      i++;
    }
    free(nums);   
}

int    get_height(char *filename)
{
    int     fd;
    int     height;
    char    *line;
 
    height = 0;
    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return(height); 
}

int    get_width(char *filename)
{
    int     fd;
    int     width;
    char    *line;

    width = 0;
    fd = open(filename, O_RDONLY);
    get_next_line(fd, &line);
    width = ft_wdcounter(line, ' ');
    free(line);
    close(fd);
    return(width);
}

void    read_file(char *filename, fdf *data)
{
    int fd;
    char *line;
    int i;
    
    data->height = get_height(filename);
    data->width = get_width(filename);
    data->a_matrix = (int **)ft_memalloc(sizeof(int*) * (data->height)); /* +1 removed*/
    i = 0;
    while (i <= data->height)
      data->a_matrix[i++] = (int *)ft_memalloc(sizeof(int) * (data->width)); /* +1 removed*/
    fd = open(filename, O_RDONLY);
    i = 0;
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->a_matrix[i], line);
        free(line);
        i++;
    }
    close(fd);
    data->a_matrix[i] = NULL;
}
