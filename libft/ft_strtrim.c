/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:53:39 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:53:50 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	char	*begin;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s))
		if ((result = ft_strnew(1)) != NULL)
			return (result);
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	result = (char*)malloc(sizeof(char) * (j - i + 2));
	if (!result)
		return (NULL);
	begin = result;
	while (i < j)
		*result++ = s[i++];
	*result = '\0';
	return (begin);
}
