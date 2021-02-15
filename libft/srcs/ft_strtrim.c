/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:00:46 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/31 13:47:28 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char		*fresh;
	size_t		end;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	end = ft_strlen(s) - 1;
	while (*s && (s[end] == ' ' || s[end] == '\n' || s[end] == '\t'))
		end--;
	end++;
	if (!(fresh = (char*)malloc(sizeof(char) * (end + 1))))
		return (NULL);
	while (end)
	{
		fresh[i] = s[i];
		i++;
		end--;
	}
	fresh[i] = '\0';
	return (fresh);
}
