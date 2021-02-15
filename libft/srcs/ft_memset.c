/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:04:33 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/18 11:09:59 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i1;

	i1 = 0;
	while (i1 < len)
	{
		*(unsigned char*)(b + i1) = (unsigned char)c;
		i1++;
	}
	return (b);
}
