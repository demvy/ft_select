/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 20:05:25 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:38:21 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;
	char *begin;

	s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == (char*)NULL)
		return ((char*)NULL);
	begin = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (begin);
}
