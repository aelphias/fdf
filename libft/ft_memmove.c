/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:03:56 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/25 19:39:27 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (ptr_src > ptr_dst)
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	}
	else
		while (len--)
		{
			ptr_dst[len] = ptr_src[len];
		}
	return ((void*)ptr_dst);
}
