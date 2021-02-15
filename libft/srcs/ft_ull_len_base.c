/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:24:36 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/25 17:26:11 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ull_len_base(unsigned long long n, int base)
{
	size_t		len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}
