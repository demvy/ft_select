/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:11:27 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/16 18:13:21 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	find_next_pos(char *str, int increment)
{
	int	pos;

	pos = 0 + increment;
	while (str[pos] != '.' && str[pos] != '\0')
		pos++;
	if (str[pos] == '\0')
		return (-1);
	return (pos);
}

static int	ft_paste(t_square *m, t_tetramin **t_tab, int current, int incr)
{
	int	pos;
	int last_pos;
	int	xy[3];

	last_pos = (int)ft_strlen(m->str) - 1;
	pos = find_next_pos(m->str, incr);
	xy[2] = pos + (t_tab[current]->fourth)->x * (m->size + 1) +
	   	(t_tab[current]->fourth)->y;
	if (pos > last_pos || xy[2] > last_pos)
		return (0);
	xy[0] = pos + (t_tab[current]->second)->x * (m->size + 1) +
		(t_tab[current]->second)->y;
	xy[1] = pos + (t_tab[current]->third)->x * (m->size + 1) +
		(t_tab[current]->third)->y;
	if (m->str[xy[0]] != '.' || m->str[xy[1]] != '.' || m->str[xy[2]] != '.')
		ft_paste(m, t_tab, current, incr + 1);
	else
	{
//		printf("%d\t%d\t%d\t%d\n", pos, xy[0], xy[1], xy[2]);
		m->str[pos] = t_tab[current]->letter;
		m->str[xy[0]] = t_tab[current]->letter;
		m->str[xy[1]] = t_tab[current]->letter;
		m->str[xy[2]] = t_tab[current]->letter;
	}
	return (1);
}

static char	*ft_clear(char *tab, char c)
{
	char	*tmp;

	tmp = tab;
	while (*tmp)
	{
		if (*tmp == c)
			*tmp = '.';
		tmp++;
	}
	return (tab);
}

int			ft_solve(t_square *map, t_tetramin **t_tab, int i)
{
	if (t_tab[i] == NULL)
		return (1);
	printf("current - %d\t%c\n%s\n", i, t_tab[i]->letter, map->str);
	if (ft_paste(map, t_tab, i, c) == 1)
	{
		if (ft_solve(map, t_tab, i + 1) == 1)
			return (1);
		ft_clear(map->str, t_tab[i]->letter);
		c +=1
	}
	return (0);
//		printf("NOOOOOOOOOOOOOO%d\n", ft_paste(map, t_tab, i, 0));
//		ft_clear(map->str, t_tab[i - 1]->letter);
//	printf("current - %d\n%s\n", i, map->str);
//	if (ft_solve(map, t_tab, i) == 1)
//		return (1);
//	i -= 1;
//	else
//		ft_clear(map->str, t_tab[i - 1]->letter);
}
