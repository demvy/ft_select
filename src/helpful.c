/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:01:07 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/04/07 13:01:10 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		change_str(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
}

size_t		ft_substrlen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int			put(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

size_t		max_len(t_lst_d *lst)
{
	t_lst_d	*first;
	t_lst_d	*curr;
	size_t	max;

	first = lst;
	curr = lst;
	max = 1;
	while (curr->next != first)
	{
		if (ft_strlen(curr->data) > max)
			max = ft_strlen(curr->data);
		curr = curr->next;
	}
	if (ft_strlen(curr->data) > max)
		max = ft_strlen(curr->data);
	return (max);
}

size_t		list_size(t_lst_d *lst)
{
	t_lst_d	*first;
	t_lst_d	*curr;
	size_t	i;

	first = lst;
	curr = lst->next;
	i = 1;
	while (curr && curr != first)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
