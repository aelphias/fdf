/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:43:05 by acarole           #+#    #+#             */
/*   Updated: 2020/01/03 16:04:46 by eleanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t i;
	size_t num;
	size_t len;

	len = ft_strlen(src);
	i = ft_strlen(dest);
	num = i;
	while (i < (num + len))
	{
		dest[i] = src[i - num];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
