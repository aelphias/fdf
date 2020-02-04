/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:14:18 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/23 15:28:42 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rslt;
	size_t	length;
	size_t	i;

	i = 0;
	length = ft_strlen(s1);
	rslt = (char*)malloc((length + 1) * sizeof(char));
	if (!rslt)
		return (NULL);
	while (i < length)
	{
		rslt[i] = s1[i];
		i++;
	}
	rslt[i] = '\0';
	return (rslt);
}
