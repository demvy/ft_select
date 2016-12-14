/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:01:26 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/13 19:01:14 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_coord		*create_coord(int x, int y)
{
	t_square	*new;

	new = malloc(sizeof(t_square));
	if (!new)
		ft_puterror(0);
	new->x = x;
	new->y = y;
	return (new);
}

static t_tetramin	*crea_tetr(char *str, char l)
{
	t_tetramin	*new;
	int			i;
	int			dash_count;

	if ((new = malloc(sizeof(t_tetramin))) == NULL)
		ft_puterror(0);
	i = -1;
	dash_count = 0;
	new->letter = l;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			dash_count++;
			if (dash_count == 1)
				new->first = create_coord(i / 5, i % 5);
			else if (dash_count == 2)
				new->second = create_coord(i / 5, i % 5);
			else if (dash_count == 3)
				new->third = create_coord(i / 5, i % 5);
			else if (dash_count == 4)
				new->fourth = create_coord(i / 5, i % 5);
		}
	}
	return (new);
}

t_tetramin			**ft_read(char *file, int *size)
{
	char		*buf;
	int			fd;
	int			ret;
	int			counter;
	t_tetramin	**tetra_list;

	counter = 0;
	if ((buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))) == 0)
		ft_puterror(0);
	if ((fd = open(file, O_RDONLY)) < 0)
	   ft_puterror(1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		t_check(buf, &counter);
		tetra_list[counter - 1] = crea_tetr(buf, 'A' + counter - 1);
	}
	return (tetra_list);
}
