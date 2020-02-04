/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 21:36:33 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/28 21:43:33 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		new_s = ft_strnew(ft_strlen(s));
		if (!new_s)
			return (NULL);
		while (s[i])
		{
			new_s[i] = f(i, s[i]);
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
