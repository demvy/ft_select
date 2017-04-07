/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:26:28 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:26:37 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char *src;

	src = (unsigned const char*)s;
	while (n-- != 0)
	{
		if (*src == (unsigned char)c)
			return ((void*)src);
		src++;
	}
	return (NULL);
}
