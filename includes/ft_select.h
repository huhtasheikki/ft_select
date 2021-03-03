/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:18:25 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/03 22:25:13 by hhuhtane         ###   ########.fr       */
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
# include <fcntl.h>

# define ERR_MALLOC 1
# define ERR_READ 2
# define ERR_MESSAGE 4
# define ERR_TERMTYPE_NOT_SET 8
# define ERR_TERMTYPE_NOT_FOUND 16
# define ERR_TERMCAPS_NO_ACCESS 32
# define ERR_SIG 64

# define MOVE_UP -1
# define MOVE_DOWN 1
# define MOVE_LEFT -1
# define MOVE_RIGHT 1

# define KEY_CTRL_Z 26
# define KEY_ESC 27

struct						s_select
{
	char					*p_argv;
	int						x;
	int						y;
	bool					select;
	bool					cursor;
};

typedef struct termios		t_termios;

struct						s_program
{
	int						fd;
	t_termios				orig_termios;
	t_list					*argv_l;
	char					*term_buffer;
	char					*termtype;
	char					*buffer;
	char					*cl_string;
	char					*cm_string;
	char					*cd_string;
	char					*so_string;
	char					*se_string;
	char					*mr_string;
	char					*me_string;
	char					*us_string;
	char					*ue_string;
	char					*vi_string;
	char					*ve_string;
	char					*ti_string;
	char					*te_string;
	int						height;
	int						width;
	size_t					arglen;
	int						col_num;
};

typedef struct s_select		t_select;
typedef struct s_program	t_prog;

/*
** GLOBALS:
*/
t_prog						*g_prog;

void						err_fatal(int error_no, char *s_str, t_prog *prog);
void						err_quit(int error_no, char *s_str);


/*
** INIT STUFF
*/

t_list						*args_to_lst2(char **argv, t_prog *prog);
void						print_lst(t_list *elem, t_prog *prog);
void						print_args(t_prog *prog);

void						enable_raw_mode(t_prog *prog);
int							disable_raw_mode(t_prog *prog);

void						init_terminal_data(t_prog *prog);
void						interrogate_terminal(t_prog *prog);

void						signals(void);

/*
** TERMCAPS COMMANDS
*/
void						terminal_clear_row(t_prog *prog);
void						move_cursor(int x, int y, t_prog *prog);

int							ft_putc(int c);
void						fun_move_cursor(int x, int y, t_prog *prog);
void						fun_move_cursor_next(t_prog *prog);
void						fun_select_cursor(t_prog *prog);
int							get_last_row_with_column_x(int x, t_list *lst);
int							get_last_column_with_row_y(int y, t_list *lst);

t_select					*get_cursor(t_list *lst);
t_select					*get_xy_select(int x, int y, t_list *select);
void						set_xy_to_argvl(t_list *lst, int col_num);
void						remove_elem(t_prog *prog);

void						react_to_keypress(char *readarr, t_prog *prog);
void						quit_no_return(t_prog *prog);
void						quit_return_selected(t_prog *prog);

int							get_longest_len(char **argv);

#endif
