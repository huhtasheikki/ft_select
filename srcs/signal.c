/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:26:35 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/01 20:22:58 by hhuhtane         ###   ########.fr       */
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
	g_prog->row_num = ws.ws_row;
	g_prog->col_num = ws.ws_col / (g_prog->arglen + 1);
	print_args(g_prog);
//	ft_printf("Rows: %d, Columns: %d\n\r", ws.ws_row, ws.ws_col);
}
