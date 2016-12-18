/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:11:27 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/18 22:32:36 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_paste(t_square *m, t_tetramin *tetr, int pos)
{
	m->str[pos] = tetr->letter;
	m->str[pos + (tetr->second)->x * (m->size + 1) +
	(tetr->second)->y] = tetr->letter;
	m->str[pos + (tetr->third)->x * (m->size + 1) +
	(tetr->third)->y] = tetr->letter;
	m->str[pos + (tetr->fourth)->x * (m->size + 1) +
	(tetr->fourth)->y] = tetr->letter;
}

void	ft_clear(char *tab, char c)
{
	char	*tmp;

	tmp = tab;
	while (*tmp)
	{
		if (*tmp == c)
			*tmp = '.';
		tmp++;
	}
}

static int	ft_check_current(int pos, t_square *m, t_tetramin *tetr, int n)
{
	int res;

	res = 0;
	if (m->str[pos] == '.' &&
		m->str[pos + (tetr->second)->x * (m->size + 1) +
		(tetr->second)->y] == '.' &&
		m->str[pos + (tetr->third)->x * (m->size + 1) +
		(tetr->third)->y] == '.' &&
		m->str[pos + (tetr->fourth)->x * (m->size + 1) +
		(tetr->fourth)->y] == '.')
	{
//		if (m->size * m->size == n * 4)
//		{
		ft_paste(m, tetr, pos);
//		res = ft_correct_position(pos, m->str, m->size);
		res = ft_check_free_space(m, pos + (tetr->fourth)->x *
		(m->size + 1) + (tetr->fourth)->y);
		ft_clear(m->str, tetr->letter);
//		}
//		else
//			res = 1;
//		printf("res = %d\tmap - \n%s\n",res,  m->str);
		return (res);
	}
	return (res);
}

static int	find_next_pos(t_square *m, t_tetramin *tetr, int pos_num, int n)
{
	int pos;
	int last_pos;

	pos = -1;
	last_pos = (int)ft_strlen(m->str) - 2;
	while (pos_num > 0 && ++pos <= last_pos)
	{
		while (m->str[pos] != '.' && m->str[pos] != '\0')
			pos++;
		if (m->str[pos] == '\0')
			return (-1);
		if (pos > last_pos || pos + (tetr->fourth)->x * (m->size + 1) +
			(tetr->fourth)->y > last_pos)
			return (-1);
		if (ft_check_current(pos, m, tetr, n) == 0)
			pos_num += 1;
		pos_num -= 1;
	}
	return (pos);
}

//it need to delete this function
static int	ft_debug(char *str, char c)
{
	int pos;

	pos = 0;
	while (str[pos] != '\0' && str[pos] != c)
		pos++;
	return (pos);
}

int			ft_solve(t_square *map, t_tetramin **t_tab, int i, int n)
{
//	int	k;
//	int prev;
	int pos;
	int pos_num;

//	if (map->str[(int)ft_strlen(map->str) - 2] != '.')
//	{
//		k = 0;
//		printf("%d\n", i);
//		prev = ft_debug(map->str, map->str[(int)ft_strlen(map->str) - 2] - 1);
//		while (++k <= 10)
//			printf("%c", map->str[(int)ft_strlen(map->str) - 2]);
//		printf("\tprev is: %d\n", prev);
//	}
//	printf("%s\n", map->str);
	if (t_tab[i] == NULL)
		return (1);
	pos_num = 1;
	while ((pos = find_next_pos(map, t_tab[i], pos_num, n)) != -1)
	{
//		printf("pos OK: %d\ttetr - %d\n", pos, i);
//		printf("pos = %d\ttetr - %d\n", pos, i);
		ft_paste(map, t_tab[i], pos);
		printf("HOHOHOHOHOHOHOHOHO\n%s\n", map->str);
		if (ft_solve(map, t_tab, i + 1, n) == 1)
			return (1);
		ft_clear(map->str, t_tab[i]->letter);
		printf("CLEEEEEEEEEEEAR\n%s\n", map->str);
		pos_num += 1;
	}
//	printf("pos NO: %d\ttetr - %d\n", pos, i);
	return (0);
}
