/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:09:29 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/13 19:01:23 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puterror(int	n)
{
	if (n == 0)
		ft_putendl("malloc error");
	if (n == 1)
		ft_putendl("open file error");
	if (n == 2)
		ft_putendl("tetramino map not valid");
	if (n == 3)
		ft_putendl("bad input parameters");
	exit(1);
}
