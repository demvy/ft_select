/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:04:12 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/16 18:13:33 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			t_amount;
	t_tetramin	**t_tab;
	t_square	*map;

	i = 0;
	t_amount = 0;
	map = NULL;
	if (argc != 2)
		ft_puterror(3);
	t_tab = ft_read(argv[1], &t_amount);
	map = ft_build_matrix(map, t_amount);
	ft_solve(map, t_tab, i);

//  it need to correct next line
//	ft_solve(t_tab, t_amount, map);
//	we need to delete all strings till ***
/*	int i = -1;
	int j = 0;

	while (t_tab[j])
		j++;
	printf("we have %d tetraminos\nanother method give us %d\n", t_amount, j);
	while (++i < t_amount)
	{
		printf("tetramin # %d\t title: %c\ncoord\nfirst  x: %d\t first  y: %d\nsecond x: %d\t second y: %d\nthird  x: %d\t third  y: %d\nfourth x: %d\t fourth y: %d\n", i + 1, t_tab[i]->letter, t_tab[i]->first->x, t_tab[i]->first->y, t_tab[i]->second->x, t_tab[i]->second->y,	t_tab[i]->third->x, t_tab[i]->third->y,	t_tab[i]->fourth->x, t_tab[i]->fourth->y);
	}*/
//	printf("%s\n%d\n", map->str, map->size);
//	**********************
	return (0);
}
