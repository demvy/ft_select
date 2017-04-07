/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:24:21 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:24:29 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *beg;
	t_list *new_lst;

	if (!lst || !f)
		return (NULL);
	beg = f(lst);
	new_lst = beg;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_lst->next = f(lst);
		new_lst = new_lst->next;
	}
	return (beg);
}
