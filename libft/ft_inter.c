/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 20:57:16 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/05 20:59:35 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_first(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

static int	is_instring(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void		ft_inter(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_instring(str2, str[i]) && is_first(str, str[i], i))
			write(1, &str[i], 1);
		i++;
	}
}
