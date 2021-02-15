/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 09:51:13 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/31 13:59:18 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	size_t		i;

	i = 0;
	if (!s && len)
		return (NULL);
	if (!(fresh = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0)
	{
		fresh[i++] = s[start++];
		len--;
	}
	fresh[i] = '\0';
	return (fresh);
}
