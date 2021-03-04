/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:11 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/04 18:09:14 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		disable_raw_mode(t_prog *prog)
{
	t_termios	orig_termios;

	tputs(prog->ve_string, 1, ft_putc);
	move_cursor(0, 0, prog);
	terminal_clear_row(prog);
	move_cursor(0, 0, prog);
	tputs(prog->te_string, 1, ft_putc);
	orig_termios = prog->orig_termios;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		err_quit(ERR_MESSAGE, "tcsetattr");
	return (1);
}

void	ft_cfmakeraw(t_termios *termios_p)
{
	termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP \
							| INLCR | IGNCR | ICRNL | IXON);
	termios_p->c_oflag &= ~OPOST;
	termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN);
	termios_p->c_cflag &= ~(CSIZE | PARENB);
	termios_p->c_cflag |= CS8;
}

/*
** enable_raw_mode - Disable these flags:
** - IXON     Disable XON/XOFF flow control on output.
** - ECHO     Disable echo input character
** - ICANON   Disable canonical mode -> read byte by byte
** - IEXTEN   Disable implementation-defined input processing.  This
**            flag, as well as ICANON must be enabled for the special
**            characters EOL2, LNEXT, REPRINT, WERASE to be interpreted,
**            and for the IUCLC flag to be effective.
** - (ISIG)   Disable signal (normal: When any of the characters INTR, QUIT,
**            SUSP, or DSUSP are received,  generate the corresponding signal).
** - OPOST    Enable implementation-defined output processing.
** - IGNBRK   Ignore BREAK condition on input.
** - BRKINT   If IGNBRK is set, a BREAK is ignored.  If it is not set
**            but BRKINT is set, then a BREAK causes the input and
**            output queues to be flushed, and if the terminal is the
**            controlling terminal of a foreground process group, it
**            will cause a SIGINT to be sent to this foreground process
**            group.  When neither IGNBRK nor BRKINT are set, a BREAK
**            reads as a null byte ('\0'), except when PARMRK is set, in
**            which case it reads as the sequence \377 \0 \0.
** - PARMRK If this bit is set, input bytes with parity or framing
**            errors are marked when passed to the program.  This bit is
**            meaningful only when INPCK is set and IGNPAR is not set.
**            The way erroneous bytes are marked is with two preceding
**            bytes, \377 and \0.  Thus, the program actually reads
**            three bytes for one erroneous byte received from the
**            terminal.  If a valid byte has the value \377, and ISTRIP
**            (see below) is not set, the program might confuse it with
**            the prefix that marks a parity error.  Therefore, a valid
**            byte \377 is passed to the program as two bytes, \377
**            \377, in this case.
**
**            If neither IGNPAR nor PARMRK is set, read a character with
**            a parity error or framing error as \0.
** - ISTRIP   Strip off eighth bit.
*/

void	enable_raw_mode(t_prog *prog)
{
	t_termios	raw;

	if (tcgetattr(STDIN_FILENO, &raw) == -1)
		err_fatal(ERR_MESSAGE, "tcgetattr", prog);
	prog->orig_termios = raw;
	ft_cfmakeraw(&raw);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		err_fatal(ERR_MESSAGE, "tcsetattr", prog);
	tputs(prog->ti_string, 1, ft_putc);
	tputs(prog->vi_string, 1, ft_putc);
}

void	print_lst(t_list *elem, t_prog *prog)
{
	int			i;
	t_select	*sel;

	i = 0;
	while (elem->next)
	{
		i++;
		elem = elem->next;
		sel = elem->content;
		if (sel->select)
			tputs(prog->mr_string, 1, ft_putc);
		if (sel->cursor)
			tputs(prog->us_string, 1, ft_putc);
		ft_printf_fd(prog->fd, "%-*s", prog->arglen, sel->p_argv);
		tputs(prog->me_string, 1, ft_putc);
		if (i == prog->col_num)
		{
			i = 0;
			ft_printf_fd(prog->fd, "\r\n");
		}
		else
			ft_putchar_fd(' ', prog->fd);
	}
	ft_printf_fd(prog->fd, "\r\n");
}

int		main(int argc, char **argv)
{
	t_prog		prog;
	char		readarr[10];

	if (argc < 2)
		exit(ft_printf("USAGE HOMMAT\n"));
	signals();
	init_terminal_data(&prog);
	interrogate_terminal(&prog);
	prog.arglen = get_longest_len(argv + 1);
	prog.col_num = prog.width / (prog.arglen + 1);
	args_to_lst2(argv + 1, &prog);
	enable_raw_mode(&prog);
	print_lst(prog.argv_l, &prog);
	while (1)
	{
		ft_bzero(readarr, 10);
		if (read(STDIN_FILENO, readarr, 10) == -1)
			err_fatal(ERR_READ, NULL, &prog);
		react_to_keypress(readarr, &prog);
	}
	disable_raw_mode(&prog);
	return (0);
}
