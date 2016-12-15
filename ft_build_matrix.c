/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 10:19:30 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/15 10:39:09 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_square_size(int amount)
{
	int	sq_size;
	int	n_dashes;

	n_dashes = amount * 4;
	sq_size = 1;
	while (sq_size * sq_size < n_dashes)
		sq_size++;
	return (sq_size);
}

char		*ft_build_matrix(int t_amount)
{
	char	*square;
	int		sq_len;
	int		sq_size;
	int		i;

	sq_size = ft_square_size(t_amount);
	sq_len = sq_size * (sq_size + 1);
	if ((square = (char*)malloc(sizeof(char) * (sq_len + 1))) == NULL)
		ft_puterror(0);
	square[len] = '\0';
	square = (char*)ft_memset(square, '.', sq_len);
	i = 1;
	while (square[i - 1] != 
}
