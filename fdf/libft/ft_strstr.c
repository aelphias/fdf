/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:37:10 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/28 15:28:22 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		size_m;
	int		i;
	int		size_b;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	size_m = ft_strlen(needle);
	size_b = ft_strlen(haystack);
	while (ft_strncmp(&haystack[i], needle, size_m) && (i <= (size_b - size_m)))
		i++;
	if ((i <= (size_b - size_m)))
		return ((char *)&haystack[i]);
	return (NULL);
}
