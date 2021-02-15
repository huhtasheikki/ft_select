/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:56:12 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/24 12:41:53 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int n)
{
	size_t		n_len;
	char		*str;

	n_len = ft_intlen_base(n, 10);
	if (!(str = (char*)malloc(sizeof(char) * (n_len + 1))))
		return (NULL);
	str[n_len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--n_len] = '8';
			n /= 10;
		}
		n *= -1;
	}
	while (n > 9)
	{
		str[--n_len] = (n % 10) + '0';
		n /= 10;
	}
	str[--n_len] = n + '0';
	return (str);
}
