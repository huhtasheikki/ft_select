/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:06:56 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/10/31 15:14:00 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*new_str;
	size_t		len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new_str[len] = '\0';
	while (len)
	{
		new_str[len - 1] = f(s[len - 1]);
		len--;
	}
	return (new_str);
}
