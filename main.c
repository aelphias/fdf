/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:23:42 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/05 22:05:44 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void check_file(int argc, char **argv)
{
  if (argc < 2 || argc > 2)
  {
    write(1, "Usage : ./fdf <filename>\n", 26);
    exit(-1);
  }
  else if (argc > 2)
  {
    write(1, "Usage : ./fdf <filename>\n", 26);
    exit(-1);
  }
  else if (/* condition */)
  {
    /* code */
  }
  
}

int deal_key(int key, fdf *data)
{
	printf("%d\n", key);
  if (key == 126)
    data->shift_y -=10;
  if (key == 125)
    data->shift_y +=10;
  if (key == 124)
    data->shift_x +=10;
  if (key == 123)
    data->shift_x -=10;
  mlx_clear_window(data->mlx_ptr, data->win_ptr);
  draw(data);
	return(0);
  /*
  126 up
125 down
124 right
123 left
53  ESC
*/
}

int main(int argc, char **argv)
{
  fdf *data;
  data = (fdf*)ft_memalloc(sizeof(fdf));
  int fd;
  check_file(argc, argv);
  fd = open(argv[1], O_RDONLY);
  if (read(fd, NULL, 0) < 0)
      write( 1, "No data found.\n", 16);
  close(fd);
  exit(-1);
    
  	//read_file(argv[1], data);
  	data->mlx_ptr = mlx_init();
  	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "fdf");
  	//mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int) x, (int) y, 0xffffff);
  	//bresenham(10, 10, 600, 300, data);
    data->zoom = 20;
  	draw(data);
    mlx_key_hook(data->win_ptr, deal_key, data);
  	mlx_loop(data->mlx_ptr);
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

/*  while (i < data->height) */
  /* {
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
  printf("width: %d\n", data->width); */
  