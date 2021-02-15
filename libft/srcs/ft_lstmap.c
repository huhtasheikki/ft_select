/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:02:25 by hhuhtane          #+#    #+#             */
/*   Updated: 2019/11/05 16:43:34 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fresh;
	t_list		*current;

	if (!lst || !f)
		return (NULL);
	if (!(current = f(lst)))
		return (NULL);
	fresh = current;
	while (lst->next)
	{
		lst = lst->next;
		if (!(current->next = f(lst)))
			return (NULL);
		current = current->next;
	}
	return (fresh);
}
