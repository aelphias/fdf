/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:35:17 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/29 20:38:35 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;
	unsigned char		cc;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	cc = (unsigned char)c;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		if (ptr_src[i] == cc)
		{
			ptr_dst[i] = ptr_src[i];
			return (&ptr_dst[i + 1]);
		}
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (NULL);
}
