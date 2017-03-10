/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:45:34 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:41:39 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*m_dst;
	const char	*m_src;
	size_t		i;
	size_t		len;

	i = dsize;
	m_dst = dst;
	m_src = src;
	while (i-- != 0 && *dst)
		dst++;
	len = dst - m_dst;
	i = dsize - len;
	if (i-- == 0)
		return (len + ft_strlen(src));
	while (*src)
	{
		if (i != 0)
		{
			*dst++ = *src;
			i--;
		}
		src++;
	}
	*dst = '\0';
	return (len + (src - m_src));
}
