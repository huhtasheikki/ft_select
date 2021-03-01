/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:18:25 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/28 16:59:08 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>
# include <sys/ioctl.h>

# define ERR_MALLOC 1
# define ERR_READ 2
# define ERR_MESSAGE 4
# define ERR_TERMTYPE_NOT_SET 8
# define ERR_TERMTYPE_NOT_FOUND 16
# define ERR_TERMCAPS_NO_ACCESS 32
# define ERR_SIG 64

extern char					PC;
extern char					*UP;
extern char					*BC;
extern short				ospeed;

struct						s_select
{
	char					*p_argv;
	char					*str;
	int						x;
	int						y;
	bool					select;
	bool					cursor;
};

typedef struct termios		t_termios;

struct						s_program
{
	t_termios				orig_termios;
	t_list					*argv_l;
	char					*term_buffer;
	char					*termtype;
	char					*buffer;
	char					*cl_string;
	char					*cm_string;
	char					*cd_string;
	int						height;
	int						width;
	int						auto_wrap;
//	char					pc;
//	char					*bc;
//	char					*up;
	int						arglen;
	int						col_num;
	int						cur_x;
	int						cur_y;
};

typedef struct s_select		t_select;
typedef struct s_program	t_prog;

void						err_fatal(int error_no, char *s_str, t_prog *prog);
void						err_quit(int error_no, char *s_str);


/*
** INIT STUFF
*/

t_list						*args_to_lst(char **argv, t_prog *prog);
t_list						*args_to_lst2(char **argv, t_prog *prog);
void						disable_raw_mode(t_prog *prog);

void						init_terminal_data(t_prog *prog);
void						interrogate_terminal(t_prog *prog);

void						sig_ttysize(int signo);

/*
** TERMCAPS COMMANDS
*/
void						terminal_clear(t_prog *prog);
void						terminal_clear_row(t_prog *prog);
void						move_cursor(t_prog *prog);
void						move_cursor_up(t_prog *prog);
void						move_cursor_down(t_prog *prog);
void						move_cursor_left(t_prog *prog);
void						move_cursor_right(t_prog *prog);

#endif
