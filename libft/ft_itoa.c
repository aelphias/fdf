/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 17:26:31 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/21 16:12:05 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_size(int nb)
{
	int	sz;

	sz = 1;
	while (nb /= 10)
		++sz;
	return (sz);
}

char		*ft_itoa(int n)
{
	char				*s;
	int					sz;
	unsigned	int		buf;

	sz = num_size(n);
	buf = n;
	if (n < 0)
	{
		buf = -n;
		sz++;
	}
	if (!(s = ft_strnew(sz)))
		return (NULL);
	s[--sz] = buf % 10 + '0';
	while (buf /= 10)
		s[--sz] = buf % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
