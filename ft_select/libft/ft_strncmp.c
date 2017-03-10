/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:43:41 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:43:48 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (*s1 || *s2)
		{
			if ((*s1 > *s2) || (*s1 < *s2))
				return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		else
			break ;
		s1++;
		s2++;
	}
	return (0);
}
