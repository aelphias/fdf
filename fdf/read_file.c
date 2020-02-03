/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:08:56 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/03 17:04:05 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_height(char *file_name)
{
    int fd;
    char *line;
    int height;
    
    height = 0; 
    fd = open(file_name, O_RDONLY);
    while (get_next_line(fd, &line))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int get_width(char *file_name)
{
    int width;
    int fd;
    char *line;
    
    fd = open(file_name, O_RDONLY);
    get_next_line(fd, &line);
    width = ft_wd_counter(line, ' ');
    free(line);
    close(fd);
    return (width);
    
}

void    fill_matrix(int *z_line, char *line)
{
    char **nums;
    int i;
    
    nums = ft_strsplit(line, ' ');
    i = 0;
    while (nums[i])
    {
        printf("{ - }");
        z_line[i] = ft_atoi(nums[i]);
        free(nums[i]);
        i++;
    }
    free(nums);
    //free(line); 
}
void    read_file(char *file_name, fdf *data)
{
    int fd;
    int i;
    char *line;
    
    data->height = get_height(file_name);
    data->width = get_width(file_name);
    fd = open(file_name, O_RDONLY);
    data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
    i = 0;
    while (i <= data->height)
        data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
    while (get_next_line(fd, &line))
    {
        fill_matrix(data->z_matrix[i], line);
        free(line);
        i++;
    }
    data->z_matrix = NULL;
    close(fd);
}