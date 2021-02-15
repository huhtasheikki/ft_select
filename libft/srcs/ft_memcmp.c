/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:31:45 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/29 16:45:25 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*s1_c;
	const unsigned char		*s2_c;

	s1_c = (const unsigned char*)s1;
	s2_c = (const unsigned char*)s2;
	if (!n)
		return (0);
	while (*s1_c == *s2_c && n--)
	{
		if (n)
		{
			s1_c++;
			s2_c++;
		}
	}
	return (*s1_c - *s2_c);
}
