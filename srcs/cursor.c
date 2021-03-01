/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:14:24 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/01 19:05:07 by hhuhtane         ###   ########.fr       */
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

int			get_last_row_with_column_x(int x, t_list *lst)
{
	t_select	*last;
	int			y;

	y = 0;
//	last = get_xy_select(x, 0, lst);
	while (lst->next)
	{
		lst = lst->next;
		last = lst->content;
		if (last->x == x)
			y = last->y;
	}
	return (y);
}

int			get_last_column_with_row_y(int y, t_list *lst)
{
	t_select	*last;
	int			x;

	x = 0;
//	last = get_xy_select(x, 0, lst);
	while (lst->next)
	{
		lst = lst->next;
		last = lst->content;
		if (last->y == y)
			x = last->x;
	}
	return (x);
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
