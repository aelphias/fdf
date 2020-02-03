/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:43:25 by aelphias          #+#    #+#             */
/*   Updated: 2019/12/25 13:14:07 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char_bits(unsigned char ch)
{
	int				size;
	unsigned char	bit;

	size = ((sizeof(unsigned char) * __CHAR_BIT__) - 1);
	while (size >= 0)
	{
		bit = (ch & (1 << size)) == 0 ? '0' : '1';
		write(1, &bit, 1);
		if ((size % 8) == 0)
			write(1, " ", 1);
		size--;
	}
	write(1, "\n", 1);
}
