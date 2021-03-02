/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:51:58 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/02 09:27:17 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	fun_move_cursor(int x, int y, t_prog *prog)
{
	t_select	*current;
	t_select	*next;

	if (!(current = get_cursor(prog->argv_l)))
		return ;
	if (!(next = get_xy_select(current->x + x, current->y + y, prog->argv_l)))
	{
		if (x == 0)
			x = current->x;
		else if (x == 1)
			x = 0;
		else
			x = get_last_column_with_row_y(current->y, prog->argv_l);
		if (y == 0)
			y = current->y;
		else if (y == 1)
			y = 0;
		else
			y = get_last_row_with_column_x(current->x, prog->argv_l);
		if (!(next = get_xy_select(x, y, prog->argv_l)))
			return ;
	}
	current->cursor = 0;
	next->cursor = 1;
	print_args(prog);
}

void	fun_move_cursor_next(t_prog *prog)
{
	t_list		*lst;
	t_select	*current;

	lst = prog->argv_l;
	while (lst->next)
	{
		lst = lst->next;
		current = lst->content;
		if (current->cursor)
		{
			current->cursor = 0;
			if (lst->next)
				current = lst->next->content;
			else
				current = prog->argv_l->next->content;
			current->cursor = 1;
			return ;
		}
	}
}

void	fun_select_cursor(t_prog *prog)
{
	t_select	*current;

	if (!(current = get_cursor(prog->argv_l)))
		return ;
	if (current->select)
		current->select = 0;
	else
		current->select = 1;
	fun_move_cursor_next(prog);
	print_args(prog);
}
