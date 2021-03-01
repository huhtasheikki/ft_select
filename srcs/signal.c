/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:26:35 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/26 18:48:28 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_ttysize(int signo)
{
	struct winsize		ws;

	(void)signo;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	ft_printf("Rows: %d, Columns: %d\n\r", ws.ws_row, ws.ws_col);
}
