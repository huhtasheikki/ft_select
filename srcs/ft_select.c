/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:11 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/01 08:58:51 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_iscntrl(int c)
{
	if ((c > 0 && c < 32) || c == 127)
		return (1);
	return (0);
}

void	disable_raw_mode(t_prog *prog)
{
	t_termios	orig_termios;

	orig_termios = prog->orig_termios;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		exit(1);
//		err_fatal(ERR_MESSAGE, "tcsetattr", prog);
}

void	ft_cfmakeraw(t_termios *termios_p)
{
	termios_p->c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP \
							| INLCR | IGNCR | ICRNL | IXON);
	termios_p->c_oflag &= ~OPOST;
	termios_p->c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
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
** - ISIG     Disable signal (normal: When any of the characters INTR, QUIT,
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
}

void	print_lst(t_list *elem, t_prog *prog)
{
	int		i;
	t_select	*sel;

	i = 0;
	ft_printf("PRINTLIST>\n\r");
	while (elem->next)
	{
		i++;
		elem = elem->next;
		sel = elem->content;
//		ft_printf("%-*s", prog->arglen + 1, elem->content);
		if (sel->cursor)
		{
			tputs(prog->mr_string, 1, ft_putc);
			ft_printf("%-*s", prog->arglen, sel->p_argv);
			tputs(prog->me_string, 1, ft_putc);
		}
		else
			ft_printf("%-*s", prog->arglen + 1, sel->p_argv);
		if (i == prog->col_num)
		{
			i = 0;
			ft_printf("\r\n");
		}
		else
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	ft_printf("\r\n");
}

int		get_longest_len(char **argv)
{
	int		len;
	int		temp;

	len = 0;
	while (*argv)
	{
		temp = ft_strlen(*argv);
		if (temp > len)
			len = temp;
		argv++;
	}
	return (len);
}

int		main(int argc, char **argv)
{
	t_prog		prog;
	char		term_buffer[2048];
//	t_list		*select;
	char		c;

	if (argc < 2)
		exit(ft_printf("USAGE HOMMAT\n"));

	if (signal(SIGWINCH, sig_ttysize) == SIG_ERR)
		err_fatal(ERR_SIG, NULL, NULL);
	ft_bzero(&prog, sizeof(t_prog));
//	prog.term_buffer = ft_memalloc(sizeof(char) * 2048);

	init_terminal_data(&prog, term_buffer);
	interrogate_terminal(&prog);
//	prog.arglen = get_longest_len(argv + 1);
	prog.col_num = prog.width / (prog.arglen + 1);
	args_to_lst2(argv + 1, &prog);
	enable_raw_mode(&prog);
//	select = args_to_lst(argv + 1, &prog);
	terminal_clear(&prog);

//	ft_printf("kolumnien maara:%d, koko:%d\r\n", prog.col_num, prog.arglen);

	print_lst(prog.argv_l, &prog);

//	ft_printf("height:%d widht:%d autowrap:%d \n\r", prog.height, prog.width, prog.auto_wrap);

/*
	int i;
    ft_printf("The ASCII value of all control characters are ");
    for (i=0; i<=127; ++i)
    {
        if (ft_iscntrl(i) != 0)
            ft_printf("%d ", i);
    }
	ft_putchar('\n');
	ft_putchar('\r');
*/

	while (1)
	{
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == -1)
			err_fatal(ERR_READ, NULL, &prog);
/*
		if (ft_iscntrl(c))
			ft_printf("%d\r\n", c);
		else if (c)
			ft_printf("%d ('%c')\r\n", c, c);
*/
		if (c == 'q')
			break;
		if (c == 'l')
			terminal_clear_row(&prog);
		if (c == 'w')
			move_cursor_up(&prog);
		if (c == 's')
			move_cursor_down(&prog);
		if (c == 'a')
			move_cursor_left(&prog);
		if (c == 'd')
			move_cursor_right(&prog);
	}

	disable_raw_mode(&prog);
	return (0);
}
