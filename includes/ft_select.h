/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:18:25 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/23 19:56:59 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <unistd.h>

# define ERR_MALLOC 1

struct						s_select
{
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
};

typedef struct s_select		t_select;
typedef struct s_program	t_prog;

void						err_fatal(int error_no, char *s_str, t_prog *prog);
void						err_quit(char *err_mess, int errorno);


/*
** INIT STUFF
*/

t_list						*args_to_lst(char **argv, t_prog *prog);
void						disable_raw_mode(t_prog *prog);

#endif
