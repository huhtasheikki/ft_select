/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:40:33 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/23 19:54:27 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		get_error_str(char *error, int error_no)
{
	if (error_no == ERR_MALLOC)
		ft_strcpy(error, "Fatal error: failed to allocate memory\n");
	else
		ft_strcpy(error, "Some random error.\n");
}

void			err_fatal(int error_no, char *s_str, t_prog *prog)
{
	char	error_message[1024];

	get_error_str(error_message, error_no);
	ft_printf_fd(2, error_message, s_str);
	disable_raw_mode(prog);
	exit(-1);
}

void	err_quit(char *err_mess, int errorno)
{
	ft_printf("%d", errorno);
	ft_putendl(err_mess);
	exit(1);
}
