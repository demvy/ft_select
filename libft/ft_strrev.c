/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:19:11 by vdemeshk          #+#    #+#             */
/*   Updated: 2016/12/05 21:19:32 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	int		lenght;
	int		n;

	n = 0;
	lenght = 0;
	while (str[lenght])
		lenght++;
	while (n < lenght / 2)
	{
		temp = str[n];
		str[n] = str[lenght - n - 1];
		str[lenght - n - 1] = temp;
		n++;
	}
	return (str);
}
