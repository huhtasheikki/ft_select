/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:00:35 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/31 15:31:59 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*char_d;
	const char		*char_s;

	char_d = (char*)dst;
	char_s = (const char*)src;
	if (!dst && !src && len)
		return (NULL);
	else if (char_d < char_s)
	{
		while (len--)
			*char_d++ = *char_s++;
	}
	else
	{
		char_d = (char*)dst + (len - 1);
		char_s = (const char*)src + (len - 1);
		while (len--)
		{
			*char_d-- = *char_s--;
		}
	}
	return (dst);
}
