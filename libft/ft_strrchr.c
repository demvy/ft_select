/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:51:00 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:51:08 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s != '\0')
		s++;
	if (c == (int)'\0')
		return ((char*)s);
	while (*--s)
	{
		if (*s == (char)c)
			return ((char*)s);
	}
	return (NULL);
}
