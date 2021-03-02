/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:26:38 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/02 17:43:23 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
** THSES GLOBALS WERE MENTIONED, BUT NOT DEFINED. I DIDN'T USE THEN.
** char		PC;
** char		*BC;
** char		*UP;
** short 	ospeed;
*/

int ft_putc(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

void	terminal_clear(t_prog *prog)
{
	tputs(prog->cl_string, 1, ft_putc);
}

void	terminal_clear_row(t_prog *prog)
{
	
	tputs(prog->cd_string, 1, ft_putc);
}

void	print_args(t_prog *prog)
{
	if (!prog->argv_l->next)
	{
		disable_raw_mode(prog);
		exit(1);
	}
	move_cursor(0, 0, prog);
	terminal_clear_row(prog);
	print_lst(prog->argv_l, prog);
}

void	move_cursor(int x, int y, t_prog *prog)
{
	tputs(tgoto(prog->cm_string, x, y), 1, ft_putc);
}

void	interrogate_terminal(t_prog *prog)
{
	char	*buffer;
//	char	*temp;

	if (!(buffer = ft_memalloc(sizeof(char) * 2048)))
		err_fatal(ERR_MALLOC, NULL, prog);
	prog->cl_string = tgetstr ("cl", &buffer);
	prog->cm_string = tgetstr ("cm", &buffer);
	prog->cd_string = tgetstr ("cd", &buffer);
	prog->height = tgetnum ("li");
	prog->width = tgetnum ("co");
	prog->so_string = tgetstr("so", &buffer);
	prog->se_string = tgetstr("se", &buffer);
	prog->mr_string = tgetstr("mr", &buffer);
	prog->me_string = tgetstr("me", &buffer);
	prog->us_string = tgetstr("us", &buffer);
	prog->ue_string = tgetstr("ue", &buffer);
	prog->vi_string = tgetstr("vi", &buffer);
	prog->ve_string = tgetstr("ve", &buffer);
	prog->ti_string = tgetstr("ti", &buffer);
	prog->te_string = tgetstr("te", &buffer);
//	temp = tgetstr ("pc", 0);
//	PC = temp ? *temp : 0;
//	BC = tgetstr ("le", 0);
//	UP = tgetstr ("up", 0);
	tputs(prog->ti_string, 1, ft_putc);
	tputs(prog->vi_string, 1, ft_putc);
}

void	init_terminal_data(t_prog *prog)
{
	int		success;

	prog->termtype = getenv("TERM");
	if (!prog->termtype)
		err_quit(ERR_TERMTYPE_NOT_SET, NULL);
	success = tgetent(prog->term_buffer, prog->termtype);
	if (success < 0)
		err_quit(ERR_TERMCAPS_NO_ACCESS, NULL);
	if (success == 0)
		err_quit(ERR_TERMTYPE_NOT_FOUND, prog->termtype);
}
