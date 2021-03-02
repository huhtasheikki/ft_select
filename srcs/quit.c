/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:31:14 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/02 17:50:31 by hhuhtane         ###   ########.fr       */
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
			ft_printf_fd(1, "%s ", sel->p_argv);
	}
	ft_putchar('\n');
	exit(1);
}
