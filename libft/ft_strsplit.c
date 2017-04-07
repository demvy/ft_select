/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:51:25 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:52:25 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int counter;

	if (!s)
		return (0);
	counter = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			counter++;
		while (*s != c && *s)
			s++;
	}
	return (counter);
}

static int	substrlen(const char *s, char c)
{
	int i;

	i = 0;
	while (*s != '\0' && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		cwords;
	int		i;

	if (!s)
		return (NULL);
	cwords = count_words(s, c);
	if (!(arr = (char**)malloc(sizeof(char*) * (cwords + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			if (substrlen(s, c) != 0 && *s)
				if ((arr[i] = ft_strsub(s, 0, substrlen(s, c))) == NULL)
					return (NULL);
			s = (s + ft_strlen(arr[i]));
			i++;
		}
	}
	arr[cwords] = NULL;
	return (arr);
}
