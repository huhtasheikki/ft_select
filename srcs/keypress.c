/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:17:08 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/04 13:10:36 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		fun_esc_keys(char *readarr, t_prog *prog)
{
	if (readarr[1] == 0)
		quit_no_return(prog);
	if (readarr[1] == 91)
	{
		if (readarr[2] == 65)
			fun_move_cursor(0, MOVE_UP, prog);
		else if (readarr[2] == 66)
			fun_move_cursor(0, MOVE_DOWN, prog);
		else if (readarr[2] == 67)
			fun_move_cursor(MOVE_RIGHT, 0, prog);
		else if (readarr[2] == 68)
			fun_move_cursor(MOVE_LEFT, 0, prog);
		else if (readarr[2] == 51 && readarr[3] == 126)
			remove_elem(prog);
	}
}

void			react_to_keypress(char *readarr, t_prog *prog)
{
	if (readarr[0] == KEY_ESC)
		fun_esc_keys(readarr, prog);
	else
	{
		if (readarr[0] == 'q')
			quit_no_return(prog);
		else if (readarr[0] == ' ')
			fun_select_cursor(prog);
		else if (readarr[0] == 127)
			remove_elem(prog);
		else if (readarr[0] == 13)
			quit_return_selected(prog);
	}
}
