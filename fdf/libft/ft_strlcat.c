/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 23:28:51 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/26 13:35:36 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;
	size_t i;
	size_t b;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	b = len_dst + len_src;
	if (!src)
		return (len_src);
	if (size > len_dst)
	{
		while (src[i] && len_dst < size - 1)
		{
			dst[len_dst] = src[i];
			i++;
			len_dst++;
		}
		dst[len_dst] = '\0';
		return (b);
	}
	return (size + len_src);
}
