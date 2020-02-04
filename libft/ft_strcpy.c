/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 21:26:19 by aelphias          #+#    #+#             */
/*   Updated: 2019/10/07 23:24:34 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *rslt;

	rslt = dst;
	while (*src != '\0')
	{
		*dst = *((char *)src);
		dst++;
		src++;
	}
	*dst = '\0';
	return (rslt);
}
