/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:48:35 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:44:17 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*begin;
	size_t	i;

	begin = dst;
	if (n != 0)
	{
		i = 0;
		while (i < n)
		{
			if (*src == '\0')
				break ;
			*begin++ = *src++;
			i++;
		}
		while (i < n)
		{
			*begin++ = '\0';
			i++;
		}
	}
	return (dst);
}
