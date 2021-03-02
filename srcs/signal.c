/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:26:35 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/02 09:21:00 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_ttysize(int signo)
{
	struct winsize		ws;

	(void)signo;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	g_prog->height = ws.ws_row;
	g_prog->width = ws.ws_col;
	g_prog->col_num = ws.ws_col / (g_prog->arglen + 1);
	set_xy_to_argvl(g_prog->argv_l, g_prog->col_num);
	print_args(g_prog);
}
