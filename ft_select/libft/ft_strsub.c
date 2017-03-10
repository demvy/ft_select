/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:53:19 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:53:27 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;
	char *beg;

	if (!s)
		return (NULL);
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	beg = substr;
	s = s + start;
	while (len-- != 0)
		*substr++ = *s++;
	*substr = '\0';
	return (beg);
}
