/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:46:25 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/02 10:46:31 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *begin;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == (char*)NULL)
		return (NULL);
	begin = str;
	while (*str)
		*str++ = '\0';
	return (begin);
}
