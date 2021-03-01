/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 11:26:38 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/28 16:57:29 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
char		PC;
char		*BC;
char		*UP;
short ospeed;
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

void	move_cursor(t_prog *prog)
{
	tputs(tgoto(prog->cm_string, prog->cur_x, prog->cur_y), 1, ft_putc);
}

void	interrogate_terminal(t_prog *prog)
{
	char	*buffer;
	char	*temp;

//	if (!(buffer = ft_memalloc(sizeof(char) * ft_strlen(prog->term_buffer))))
	if (!(buffer = ft_memalloc(sizeof(char) * ft_strlen(prog->termtype))))
		err_fatal(ERR_MALLOC, NULL, prog);
//	prog->buffer = buffer;
  /* Extract information we will use.  */
	prog->cl_string = tgetstr ("cl", &buffer);
	prog->cm_string = tgetstr ("cm", &buffer);
	prog->cd_string = tgetstr ("cd", &buffer);
	prog->auto_wrap = tgetflag ("am");
	prog->height = tgetnum ("li");
	prog->width = tgetnum ("co");

  /* Extract information that termcap functions use.  */
	temp = tgetstr ("pc", &buffer);
	PC = temp ? *temp : 0;
	BC = tgetstr ("le", &buffer);
	UP = tgetstr ("up", &buffer);
}

void	init_terminal_data(t_prog *prog)
{
	int		success;

//	ft_bzero(prog, sizeof(t_prog));
//	ft_bzero(prog->term_buffer, 2048);
	prog->termtype = getenv("TERM");
	if (!prog->termtype)
		err_quit(ERR_TERMTYPE_NOT_SET, NULL);
	success = tgetent(prog->term_buffer, prog->termtype);
	if (success < 0)
		err_quit(ERR_TERMCAPS_NO_ACCESS, NULL);
	if (success == 0)
		err_quit(ERR_TERMTYPE_NOT_FOUND, prog->termtype);
//	tputs(tgetstr("cl", NULL), 1, ft_putc);
}
