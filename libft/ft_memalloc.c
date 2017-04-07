/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:25:39 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/05 20:34:03 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *allmem;

	if ((allmem = malloc(size)) != NULL)
	{
		ft_bzero(allmem, size);
		return (allmem);
	}
	else
		return (NULL);
}
