/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:47:47 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/11/04 11:28:55 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i1;
	size_t		i2;

	i1 = 0;
	if (!*needle)
		return ((char*)haystack);
	while (i1 < len && haystack[i1])
	{
		i2 = 0;
		while (i1 + i2 < len && haystack[i1 + i2] == needle[i2])
		{
			i2++;
			if (!needle[i2])
				return ((char*)&haystack[i1]);
		}
		i1++;
	}
	return (NULL);
}
