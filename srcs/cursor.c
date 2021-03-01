/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:14:24 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/01 11:24:36 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*get_cursor(t_list *lst)
{
	t_select	*select;

	while (lst->next)
	{
		lst = lst->next;
		select = lst->content;
		if (select->cursor)
			return (select);
	}
	return (NULL);
}

t_select	*get_xy_select(int x, int y, t_list *lst)
{
	t_select	*select;

	while (lst->next)
	{
		lst = lst->next;
		select = lst->content;
		if (select->x == x && select->y == y)
			return (select);
	}
	return (NULL);
}
