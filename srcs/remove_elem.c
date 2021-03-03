/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:30:37 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/03 20:34:39 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		del_argvl_elem(void *elem, size_t size)
{
	ft_bzero(elem, size);
	free(elem);
}

static void		set_lst_cursor(t_list *lst)
{
	t_select	*select;

	if (!lst || lst->content_size == 0)
		return ;
	select = lst->content;
	select->cursor = 1;
}

static t_list	*get_cursor_lst(t_list *lst)
{
	t_select	*current;

	while (lst->next)
	{
		lst = lst->next;
		current = lst->content;
		if (current->cursor)
			return (lst);
	}
	return (NULL);
}

void			remove_elem(t_prog *prog)
{
	t_list		*current;
	t_list		*prev;

	prev = prog->argv_l;
	if (!(current = get_cursor_lst(prog->argv_l)))
		return ;
	while (prev->next != current)
		prev = prev->next;
	prev->next = current->next;
	ft_lstdelone(&current, &del_argvl_elem);
	if (prev->next)
		set_lst_cursor(prev->next);
	else
		set_lst_cursor(prev);
	if (!prog->argv_l->next)
		quit_no_return(prog);
	set_xy_to_argvl(prog->argv_l, prog->col_num);
	print_args(prog);
}
