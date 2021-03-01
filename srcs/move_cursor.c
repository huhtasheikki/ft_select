/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:51:58 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/01 11:42:53 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_up(t_prog *prog)
{
	t_select	*current;
	t_select	*next;
	int			x;
	int			y;

	if (!(current = get_cursor(prog->argv_l)))
		return ;
	x = current->x;
	y = current->y - 1;
	if (!(next = get_xy_select(x, y, prog->argv_l)))
		return ;
	current->cursor = 0;
	next->cursor = 1;
	move_cursor(0, 0, prog);
	terminal_clear_row(prog);
	print_lst(prog->argv_l, prog);
}

void	move_cursor_down(t_prog *prog)
{
	t_select	*current;
	t_select	*next;
	int			x;
	int			y;

	if (!(current = get_cursor(prog->argv_l)))
		return ;
	x = current->x;
	y = current->y + 1;
	if (!(next = get_xy_select(x, y, prog->argv_l)))
		return ;
	current->cursor = 0;
	next->cursor = 1;
	move_cursor(0, 0, prog);
	terminal_clear_row(prog);
	print_lst(prog->argv_l, prog);
//	if (prog->cur_y < prog->height - 1)
//		prog->cur_y++;
//	move_cursor(prog);
}

void	move_cursor_left(t_prog *prog)
{
	if (prog->cur_x != 0)
		prog->cur_x--;
	move_cursor(0, 0, prog);
}

void	move_cursor_right(t_prog *prog)
{
	if (prog->cur_x < prog->width - 1)
		prog->cur_x++;
	move_cursor(0, 0, prog);
}
