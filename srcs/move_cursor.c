/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:51:58 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/27 13:19:36 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_cursor_up(t_prog *prog)
{
	if (prog->cur_y != 0)
		prog->cur_y--;
	move_cursor(prog);
}

void	move_cursor_down(t_prog *prog)
{
	if (prog->cur_y < prog->height - 1)
		prog->cur_y++;
	move_cursor(prog);
}

void	move_cursor_left(t_prog *prog)
{
	if (prog->cur_x != 0)
		prog->cur_x--;
	move_cursor(prog);
}

void	move_cursor_right(t_prog *prog)
{
	if (prog->cur_x < prog->width - 1)
		prog->cur_x++;
	move_cursor(prog);
}
