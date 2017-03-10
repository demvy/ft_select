/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:10:51 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/05 21:12:27 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_range(int start, int end)
{
	int	*tab;
	int	i;

	i = 0;
	while ((start + i) <= end)
		i++;
	if (!(tab = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	i = -1;
	while ((start + ++i) <= end)
		tab[i] = start + i;
	return (tab);
}

static int	*ft_rangei(int start, int end)
{
	int	*tab;
	int	i;

	i = 0;
	while ((start + i) <= end)
		i++;
	if (!(tab = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	i = -1;
	while ((end - ++i) >= start)
		tab[i] = end - i;
	return (tab);
}

int			*ft_rrange(int start, int end)
{
	if (start < end)
		return (ft_rangei(start, end));
	return (ft_range(end, start));
}
