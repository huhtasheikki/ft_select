/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:11 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/23 19:57:28 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
t_select	*new_select(char *str)
{
	t_select	*new;

	if (!(new = ft_memalloc(sizeof(t_select))))
		return (NULL);
	if (!(new->content = ft_strdup(str)))
	{
		ft_memdel(&new);
		return (NULL);
	}
	return (new);
}
*/

/*
static t_select		arg_to_select(char *arg)
{
	t_select	select;

	ft_bzero(&select, sizeof(t_select));
	if (!(select.str = ft_strdup(arg)))
		err_fatal(ERR_MALLOC, NULL);
	return (select);
}
*/

t_list	*args_to_lst(char **argv, t_prog *prog)
{
	t_select	select;
	t_list		*lst;
	t_list		*ptr;
	t_list		*new;

	if (!(lst = ft_lstnew(NULL, 0)))
		err_fatal(ERR_MALLOC, NULL, prog);
	ptr = lst;
	ft_bzero(&select, sizeof(t_select));
	while (*argv)
	{
		if (!(select.str = ft_strdup(*argv)))
			err_fatal(ERR_MALLOC, NULL, prog);
		if (!(new = ft_lstnew(&select, sizeof(t_select))))
			err_fatal(ERR_MALLOC, NULL, prog);
		ft_lstadd(&ptr, new);
		argv++;
		ptr = ptr->next;
	}
	return (lst);
}
