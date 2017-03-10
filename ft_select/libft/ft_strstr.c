/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:53:01 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:53:09 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*begin_needle;
	const char	*hay;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		hay = haystack;
		begin_needle = needle;
		while (*begin_needle == *hay++ && *begin_needle)
			begin_needle++;
		if (*begin_needle == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
