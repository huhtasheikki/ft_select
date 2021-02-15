/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:04:27 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/29 16:23:59 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			c_char;
	const unsigned char		*src_char;
	unsigned char			*dst_char;

	c_char = (unsigned char)c;
	src_char = src;
	dst_char = dst;
	while (n--)
	{
		if (*src_char == c_char)
		{
			*dst_char++ = *src_char++;
			return (dst_char);
		}
		*dst_char++ = *src_char++;
	}
	dst_char = NULL;
	return (dst_char);
}
