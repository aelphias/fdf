/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 16:05:44 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/29 19:14:53 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int loc;
	unsigned int i;

	if (!*needle)
		return ((char*)haystack);
	loc = 0;
	while (haystack[loc] != '\0' && (size_t)loc < len)
	{
		if (haystack[loc] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[loc + i] == needle[i] &&
				(size_t)(loc + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char*)&haystack[loc]);
		}
		++loc;
	}
	return (0);
}
