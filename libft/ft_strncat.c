/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:33:14 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:43:18 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*begin;

	begin = dst;
	while (*dst)
		dst++;
	while (*src && n != 0)
	{
		*dst++ = *src++;
		n--;
	}
	*dst = '\0';
	return (begin);
}
