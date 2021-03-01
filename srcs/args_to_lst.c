/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 09:27:11 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/02/28 16:46:35 by hhuhtane         ###   ########.fr       */
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

t_list	*args_to_lst2(char **argv, t_prog *prog)
{
//	t_select	select;
	t_list		*ptr;
//	t_list		*new;
	int			x;
	int			y;

	x = 0;
	y = 0;
	ptr = NULL;
	ft_putendl("RORO1");
//	if (!(prog->argv_l = ft_lstnew(NULL, 0)))
	if (!(ptr = ft_lstnew(NULL, 0)))
		ft_putendl("roro1.2");
//		err_fatal(ERR_MALLOC, NULL, prog);
	ft_putendl("RORO22");
//	ptr = prog->argv_l;
	(void)argv;
	(void)prog;
//	ft_bzero(&select, sizeof(t_select));

/*
	while (*argv)
	{

		select.p_argv = *argv;
		select.str = NULL;
		select.x = x;
		select.y = y;
		select.select = 0;
		select.cursor = 0;

		new = ft_lstnew(&select, sizeof(t_select));
		ptr->next = new;
		ptr = ptr->next;
		ptr->next = NULL;
		argv++;
		if (x < prog->col_num)
			x++;
		else
		{
			x = 0;
			y++;
		}
	}
*/
	return (ptr);
//	return (prog->argv_l);
}

t_list	*args_to_lst(char **argv, t_prog *prog)
{
//	t_select	select;
	t_list		*lst;
	t_list		*ptr;
//	t_list		*new;

	if (!(lst = ft_lstnew(NULL, 0)))
		err_fatal(ERR_MALLOC, NULL, prog);
	ptr = lst;
//	ft_bzero(&select, sizeof(t_select));
	while (*argv)
	{
//		if (!(select.str = ft_strdup(*argv)))
//		if (!(select.str = *argv))
//			err_fatal(ERR_MALLOC, NULL, prog);
//		if (!(new = ft_lstnew(&select, sizeof(t_select))))
		if (!(ptr->next = ft_lstnew(*argv, sizeof(char) * (ft_strlen(*argv) + 1))))
			err_fatal(ERR_MALLOC, NULL, prog);
//		ft_lstadd(&ptr, new);
		argv++;
		ptr = ptr->next;
	}

//	t_select *sel;
//	ft_printf("TESTI\n\r");
//	sel = lst->next->content;
//	ft_printf("TESTI\n\r");
//	ft_printf("%s\n\r", lst->next->content);
	return (lst);
}
