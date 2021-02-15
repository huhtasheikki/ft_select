/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:22:28 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/31 15:15:21 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*fresh;
	size_t		len;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * (len))))
		return (NULL);
	while (len-- && *s1)
		fresh[i++] = *s1++;
	while (len-- && *s2)
		fresh[i++] = *s2++;
	fresh[i] = '\0';
	return (fresh);
}
