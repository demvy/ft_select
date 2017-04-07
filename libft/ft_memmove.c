/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:28:32 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:28:41 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*begin;
	const char	*s;
	char		*d;

	s = (char*)src;
	d = (char*)dst;
	begin = dst;
	if (s > d)
		while (len-- != 0)
			*d++ = *s++;
	else
	{
		while (len != 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return ((void*)begin);
}
