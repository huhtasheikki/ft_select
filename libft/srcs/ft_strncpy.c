/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:11:59 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/22 14:38:21 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i1;

	i1 = 0;
	while (src[i1] && i1 < len)
	{
		dst[i1] = src[i1];
		i1++;
	}
	while (i1 < len)
		dst[i1++] = '\0';
	return (dst);
}
