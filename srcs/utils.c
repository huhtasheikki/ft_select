/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 22:18:31 by hhuhtane          #+#    #+#             */
/*   Updated: 2021/03/03 22:24:27 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_longest_len(char **argv)
{
	int		len;
	int		temp;

	len = 0;
	while (*argv)
	{
		temp = ft_strlen(*argv);
		if (temp > len)
			len = temp;
		argv++;
	}
	return (len);
}

void	print_args(t_prog *prog)
{
	if (!prog->argv_l->next)
		quit_no_return(prog);
	move_cursor(0, 0, prog);
	terminal_clear_row(prog);
	print_lst(prog->argv_l, prog);
}
