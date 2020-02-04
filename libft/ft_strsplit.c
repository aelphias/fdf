/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelphias <aelphias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:24:34 by aelphias          #+#    #+#             */
/*   Updated: 2019/09/29 18:56:59 by aelphias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(char const *s, char c)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		if (*s == c && *s != '\0')
			s++;
		else
		{
			while (*s != c && *s != '\0')
				s++;
			n++;
		}
	}
	return (n);
}

static	void	ft_free_all(char **str, size_t i)
{
	while (i > 0)
	{
		ft_strdel(&str[i]);
		i--;
	}
	ft_strdel(str);
}

static	char	*next_word(char const *s, char c, size_t *start)
{
	size_t l;

	while (s[*start] == c)
		*start += 1;
	l = *start;
	while (s[*start])
	{
		if (s[*start] == c)
			break ;
		*start += 1;
	}
	return (ft_strsub(s, l, *start - l));
}

char			**ft_strsplit(char const *s, char c)
{
	int		words;
	size_t	i;
	size_t	start;
	char	**str;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	str = (char**)malloc(sizeof(char*) * (words + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (words--)
	{
		str[i] = next_word(s, c, &start);
		if (!(str[i]))
			ft_free_all(str, i);
		i++;
	}
	str[i] = NULL;
	return (str);
}
