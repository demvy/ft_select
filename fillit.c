/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:04:12 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/13 18:11:05 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int			t_amount;
	t_tetramin	**t_tab;

	t_amount = 0;
	if (argc != 2)
		ft_puterror(3);
	t_tab = ft_read(argv[1], &t_amount);
//	we need to delete all strings till ***
	int i = -1;
	printf("we have %d tetraminos\n", t_amount);
	while (++i < t_amount)
	{
		printf("tetramin # %d\t title: %c\ncoord\nfirst  x: %d\t first  y: %d\nsecond x: %d\t second y: %d\nthird  x: %d\t third  y: %d\nfourth x: %d\t fourth y: %d\n", i + 1, t_tab[i]->letter, t_tab[i]->first->x, t_tab[i]->first->y, t_tab[i]->second->x, t_tab[i]->second->y,	t_tab[i]->third->x, t_tab[i]->third->y,	t_tab[i]->fourth->x, t_tab[i]->fourth->y);
	}
//	**********************
	return (0);
}
