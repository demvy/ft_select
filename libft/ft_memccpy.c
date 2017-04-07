/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:26:02 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:26:11 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	if (n == 0)
		return (NULL);
	while (n-- != 0)
	{
		if (*s != (unsigned char)c)
			*d++ = *s++;
		else
		{
			*d++ = *s++;
			return (d);
		}
	}
	return (NULL);
}
