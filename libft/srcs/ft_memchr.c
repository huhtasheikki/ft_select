/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:27:50 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/21 13:58:20 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s_ptr;
	unsigned char			c_char;

	s_ptr = s;
	c_char = (unsigned char)c;
	while (n--)
	{
		if (*(s_ptr) == c_char)
			return ((void *)s_ptr);
		s_ptr++;
	}
	return (NULL);
}
