/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:23:12 by acarole           #+#    #+#             */
/*   Updated: 2020/02/12 19:37:31 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

void	ft_memdel1(char **mem)
{
	if (mem && *mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

void	ft_memdel3(int **mem)
{
	if (mem && *mem)
	{
		free(*mem);
		*mem = NULL;
	}
}
