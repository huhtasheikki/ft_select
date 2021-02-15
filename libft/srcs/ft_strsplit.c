/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:01:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/02/21 11:41:04 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_str_len(char const *s, char c)
{
	size_t		letters;

	letters = 0;
	while (*s && *s != c)
	{
		s++;
		letters++;
	}
	return (letters + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**fresh;
	size_t		i1;
	size_t		i2;

	i1 = 0;
	if (!s || !(fresh = (char**)malloc(sizeof(char*) * ft_array_len(s, c))))
		return (NULL);
	while (*s)
	{
		i2 = 0;
		while (*s == c)
			s++;
		if (*s && !(fresh[i1] = (char*)malloc(sizeof(char) * ft_str_len(s, c))))
			return (NULL);
		while (*s && *s != c)
		{
			fresh[i1][i2++] = *s++;
			if (*s == c || *s == '\0')
				fresh[i1++][i2] = '\0';
		}
	}
	fresh[i1] = NULL;
	return (fresh);
}
