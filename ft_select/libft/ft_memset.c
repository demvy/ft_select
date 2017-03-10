/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:34:49 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:29:04 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *d;

	d = b;
	if (len == 0)
		return (b);
	else
	{
		while (len > 0)
		{
			*d++ = (unsigned char)c;
			len--;
		}
		return (b);
	}
}
