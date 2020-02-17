/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:10:00 by aelphias          #+#    #+#             */
/*   Updated: 2020/02/17 18:06:56 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	check_symbols(char **argv)
{
	char	*line;
	int		fd;
	int i;
	
	i = 0;
	fd = open(argv[1], O_RDONLY, 0);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
		while (line[i])
		{
			// if (!((line[i] >= '0' && line[i] <= '9') ||
			// (line[i] >= 'A' && line[i] <= 'F') ||
			// (line[i] == 'x') || (line[i] == ' ')))
			{
				printf("something wrong happend\n");
				write(1, "invalid file\n", 14);
				free(line); // rec com
				close(fd); // rec com
				exit(-4);
			}
			i++;
		}	
		free(line);
	}
	close(fd);
}

void	check_width(char **argv)
{
	int		width_1;
	int		width_2;
	int		fd;
	char	*line;

	width_1 = 0;
	width_2 = 0;
	fd = open(argv[1], O_RDONLY, 0);
	get_next_line(fd, &line);
	free(line);
	width_1 = ft_wdcounter(line, ' ');
	while (get_next_line(fd, &line))
	{
		width_2 = ft_wdcounter(line, ' ');
		free(line);
		if (width_1 != width_2)
		{
			write(1, "invalid file\n", 14);
			close(fd);
			exit(-2);
		}
	}
	close(fd);
}

void	check_input(int argc, char **argv)
{
	int fd;

	if (argc < 2 || argc > 2)
	{
		write(1, "Usage : ./fdf <filename>\n", 26);
		exit(-1);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (read(fd, NULL, 0) < 0)
		{
			write(1, "No data found.\n", 16);
			exit(-2);
		}
		close(fd);
	}
	check_width(argv);
	check_symbols(argv);
}

