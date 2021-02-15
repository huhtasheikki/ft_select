/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:36:43 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/31 18:37:28 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i1;
	size_t		i2;

	i1 = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i1])
	{
		i2 = 0;
		while (haystack[i1] == needle[i2])
		{
			i1++;
			i2++;
			if (needle[i2] == '\0')
				return ((char*)&haystack[i1 - i2]);
		}
		i1 -= i2;
		i1++;
	}
	return (NULL);
}
