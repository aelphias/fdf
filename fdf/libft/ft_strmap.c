/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:52:36 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/28 21:14:09 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	size_t	i;

	if (s && f)
	{
		i = 0;
		new_s = ft_strnew(ft_strlen(s));
		if (!new_s)
			return (NULL);
		while (s[i])
		{
			new_s[i] = f(s[i]);
			i++;
		}
		return (new_s);
	}
	return (NULL);
}
