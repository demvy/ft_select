/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:22:18 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:22:22 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_length(int num)
{
	int		res;
	long	n;

	n = num;
	res = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		res++;
		n = -n;
	}
	while (!(n >= 0 && n <= 9))
	{
		res++;
		n /= 10;
	}
	return (res + 1);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;
	int		is_positive;

	is_positive = 1;
	len = number_length(n);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		is_positive = -1;
	i = len - 1;
	while (i >= 0)
	{
		res[i--] = (n % 10) * (is_positive) + '0';
		n /= 10;
	}
	if (is_positive == -1)
		res[0] = '-';
	return (res);
}
