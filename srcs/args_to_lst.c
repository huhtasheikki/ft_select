/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:11 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/02 09:23:20 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_xy_to_argvl(t_list *lst, int col_num)
{
	t_select	*sel;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (lst->next)
	{
		lst = lst->next;
		sel = lst->content;
		sel->x = x;
		sel->y = y;
		if (x < col_num - 1)
			x++;
		else
		{
			x = 0;
			y++;
		}
	}
}

t_list	*args_to_lst2(char **argv, t_prog *prog)
{
	t_select	select;
	t_list		*ptr;
	t_list		*new;

	ptr = NULL;
	if (!(prog->argv_l = ft_lstnew(NULL, 0)))
		err_fatal(ERR_MALLOC, NULL, prog);
	ptr = prog->argv_l;
	ft_bzero(&select, sizeof(t_select));
	select.cursor = 1;
	while (*argv)
	{
		select.p_argv = *argv;
		if ((ft_strlen(*argv)) > prog->arglen)
			prog->arglen = ft_strlen(*argv);
		new = ft_lstnew(&select, sizeof(t_select));
		ptr->next = new;
		ptr = ptr->next;
		ptr->next = NULL;
		argv++;
		select.cursor = 0;
	}
	set_xy_to_argvl(prog->argv_l, prog->col_num);
	return (prog->argv_l);
}
