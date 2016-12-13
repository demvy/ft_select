/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:01:26 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/13 19:01:14 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	**ft_read(char *file, int *size)
{
	char	*buf;
	int		fd;
	int		ret;
	int		counter;

	counter = 0;
	if ((buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))) == 0)
		ft_puterror(0);
	if ((fd = open(file, O_RDONLY)) < 0)
	   ft_puterror(1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		t_check(buf, &counter);
	}
}
