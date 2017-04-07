/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:50:37 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 13:27:09 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	a;
	char	*begin_needle;
	char	*hay;

	if (*n == '\0')
		return ((char*)h);
	while (*h && len)
	{
		hay = (char*)h;
		begin_needle = (char*)n;
		a = len;
		while (*begin_needle == *hay && *begin_needle && a)
		{
			hay++;
			begin_needle++;
			a--;
		}
		if (*begin_needle == '\0')
			return ((char*)h);
		h++;
		len--;
	}
	return (NULL);
}
