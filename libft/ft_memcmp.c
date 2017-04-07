/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:26:59 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:27:06 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *s;
	unsigned const char *d;

	s = s2;
	d = s1;
	while (n-- != 0)
	{
		if ((*d > *s) || (*d < *s))
			return (*(unsigned char*)d - *(unsigned char*)s);
		d++;
		s++;
	}
	return (0);
}
