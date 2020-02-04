/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:23:42 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/04 16:36:03 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
  fdf *data;
  int i;
  int j;
  if (argc != 2)
    return(printf("invalid input"));
  i = 0;
  data = (fdf*)malloc(sizeof(fdf));
  read_file(argv[1], data);
  while (i < data->height)
  {
    j = 0;
    while (j < data->width)
    {
      printf("%-3d", data->a_matrix[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }
  printf("height: %d\n", data->height);
  printf("width: %d\n", data->width);
  return (0);
}
/* int main(void)
{
  void *mlx;
  void *window;
  
  mlx = mlx_init();
  window = mlx_new_window(mlx, 500, 500, "fdf");
  
  mlx_loop(mlx);
  return (0);
} */