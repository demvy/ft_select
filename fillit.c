/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:04:12 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/19 22:45:10 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			t_amount;
	t_tetramin	**t_tab;
	t_square	*map;
	int			tetr_index;

	tetr_index = 0;
	t_amount = 0;
	map = NULL;
	if (argc == 1)
		ft_puterror(3);
	if (argc > 2)
		ft_puterror(4);
	t_tab = ft_read(argv[1], &t_amount);
	map = ft_build_matrix(map, t_amount);
	while(ft_solve(map, t_tab, tetr_index, t_amount) == 0)
	{
		printf("+1\n");
		map = ft_build_matrix(map, t_amount);
	}
	ft_output(map->str);
	return (0);
}
