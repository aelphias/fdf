/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarole <acarole@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:50:10 by acarole           #+#    #+#             */
/*   Updated: 2020/02/09 17:08:23 by acarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = (char *)ft_memalloc(sizeof(*str) * (len + 1));
	if (str)
	{
		while (i < len)
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = 0;
	}
	return (str);
}
