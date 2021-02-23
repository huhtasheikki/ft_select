/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:11 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/23 21:33:18 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#include <ctype.h> // remove (iscntrl)
#include <stdio.h> // remove (printf)

int		ft_iscntrl(int c)
{
	if (c < 32 || c == 127)
		return (1);
	return (0);
}

void	disable_raw_mode(t_prog *prog)
{
	t_termios	orig_termios;

	orig_termios = prog->orig_termios;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
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

	tcgetattr(STDIN_FILENO, &raw);
	prog->orig_termios = raw;
//	raw.c_iflag &= ~(ICRNL | IXON);
//	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	ft_cfmakeraw(&raw);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int		main(int argc, char **argv)
{
	t_prog		prog;
	t_list		*select;
	char		c;

	if (argc < 2)
		exit(ft_printf("USAGE HOMMAT\n"));
	enable_raw_mode(&prog);
	select = args_to_lst(argv, &prog);

	int i;
    printf("The ASCII value of all control characters are ");
    for (i=0; i<=127; ++i)
    {
        if (iscntrl(i)!=0)
            printf("%d ", i);
    }

  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
    if (ft_iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d ('%c')\r\n", c, c);
    }
  }

	disable_raw_mode(&prog);
	return (0);
}
