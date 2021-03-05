/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:31:14 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/05 10:52:17 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	quit_no_return(t_prog *prog)
{
	disable_raw_mode(prog);
	exit(1);
}

void	quit_return_selected(t_prog *prog)
{
	t_list		*ptr;
	t_select	*sel;

	ptr = prog->argv_l;
	disable_raw_mode(prog);
	while (ptr->next)
	{
		ptr = ptr->next;
		sel = ptr->content;
		if (sel->select)
		{
			ft_printf_fd(prog->fd, "%s", sel->p_argv);
			if (ptr->next)
				ft_putchar_fd(' ', prog->fd);
		}
	}
	ft_putchar_fd('\n', prog->fd);
	exit(1);
}
