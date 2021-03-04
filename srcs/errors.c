/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:40:33 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/04 20:09:28 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		get_error_str(char *buf, int error_no)
{
	if (error_no == ERR_MALLOC)
		ft_strcpy(buf, "Fatal error: failed to allocate memory\n");
	else if (error_no == ERR_READ)
		ft_strcpy(buf, "Fatal error: failed to read\n");
	else if (error_no == ERR_MESSAGE)
		ft_strcpy(buf, "Fatal error: %s failed\n");
	else if (error_no == ERR_TERMTYPE_NOT_SET)
		ft_strcpy(buf, "Specify a terminal type with `setenv TERM <type>'.\n");
	else if (error_no == ERR_TERMCAPS_NO_ACCESS)
		ft_strcpy(buf, "Could not access the termcap data base.\n");
	else if (error_no == ERR_TERMTYPE_NOT_FOUND)
		ft_strcpy(buf, "Terminal type `%s' is not defined.\n");
	else
		ft_strcpy(buf, "Some random error.\n");
}

void			err_fatal(int error_no, char *s_str, t_prog *prog)
{
	char	error_message[1024];

	get_error_str(error_message, error_no);
	disable_raw_mode(prog);
	ft_printf_fd(2, error_message, s_str);
	exit(1);
}

void			err_quit(int error_no, char *s_str)
{
	char	error_message[1024];

	get_error_str(error_message, error_no);
	ft_printf_fd(2, error_message, s_str);
	exit(1);
}
