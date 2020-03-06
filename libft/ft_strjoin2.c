/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:37:26 by eleanna           #+#    #+#             */
/*   Updated: 2020/02/09 17:03:45 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin2(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	str = (char *)ft_memalloc(len + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		str[i] = s1[i];
		i++;
	}
	str = ft_strcat(str, s2);
	free((void*)s1);
	return (str);
}
