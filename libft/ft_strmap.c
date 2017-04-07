/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:42:14 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:42:23 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *str;
	char *beg;

	if (!s || !f)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	beg = str;
	while (*s)
	{
		*str = f(*s);
		str++;
		s++;
	}
	*str = '\0';
	return (beg);
}
