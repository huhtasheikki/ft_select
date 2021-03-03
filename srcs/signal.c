/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:26:35 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/03 20:04:51 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		sig_handler(int signo)
{
	struct winsize		ws;

	if (signo == SIGWINCH)
	{
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		g_prog->height = ws.ws_row;
		g_prog->width = ws.ws_col;
		g_prog->col_num = ws.ws_col / (g_prog->arglen + 1);
		set_xy_to_argvl(g_prog->argv_l, g_prog->col_num);
	}
	else if (signo == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		ioctl(g_prog->fd, TIOCSTI, "\x1A");
		disable_raw_mode(g_prog);
		return ;
	}
	else if (signo == SIGCONT)
	{
		enable_raw_mode(g_prog);
		signal(SIGTSTP, sig_handler);
	}
	else
		exit(disable_raw_mode(g_prog));
	print_args(g_prog);
}

void			signals(void)
{
	if (signal(SIGWINCH, sig_handler) == SIG_ERR)
		err_fatal(ERR_SIG, NULL, NULL);
	if (signal(SIGCONT, sig_handler) == SIG_ERR)
		err_fatal(ERR_SIG, NULL, NULL);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		err_fatal(ERR_SIG, NULL, NULL);
	if (signal(SIGTSTP, sig_handler) == SIG_ERR)
		err_fatal(ERR_SIG, NULL, NULL);
	if (signal(SIGTERM, sig_handler))
		err_fatal(ERR_SIG, NULL, NULL);
	if ((signal(SIGQUIT, sig_handler) == SIG_ERR) || \
		(signal(SIGHUP, sig_handler) == SIG_ERR) || \
		(signal(SIGPIPE, sig_handler) == SIG_ERR) || \
		(signal(SIGALRM, sig_handler) == SIG_ERR) || \
		(signal(SIGXCPU, sig_handler) == SIG_ERR) || \
		(signal(SIGXFSZ, sig_handler) == SIG_ERR) || \
		(signal(SIGVTALRM, sig_handler) == SIG_ERR) || \
		(signal(SIGPROF, sig_handler) == SIG_ERR))
		err_fatal(ERR_SIG, NULL, NULL);
}
