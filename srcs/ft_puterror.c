/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:09:29 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/21 19:20:11 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_puterror(int n)
{
	if (n == 0)
		ft_putendl("malloc error");
	if (n == 1)
		ft_putendl("open file error");
	if (n == 2)
		ft_putendl("tetramino map not valid");
	if (n == 3)
	{
		ft_putendl("fillit: missing file with tetramins");
		ft_putendl("Try ./fillit <valid file name>");
	}
	if (n == 4)
	{
		ft_putendl("fillit: too many arguments");
		ft_putendl("Try ./fillit <valid file name>");
	}
	exit(1);
}
