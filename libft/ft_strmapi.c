/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:42:33 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:42:42 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	char			*beg;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	beg = str;
	while (*s)
	{
		*str++ = f(i++, *s);
		s++;
	}
	*str = '\0';
	return (beg);
}
