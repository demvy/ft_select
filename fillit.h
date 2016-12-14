/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:58:04 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/13 19:01:30 by oshudria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLIT_H
# define _FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# define BUF_SIZE 21
# define T_MAX 26

void				ft_puterror(int n);
void				t_check(char *str, int **counter);

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct  	s_tetramin
{
	char 			letter;
	struct s_coord	*first;
	struct s_coord	*second;
	struct s_coord	*third;
	struct s_coord	*fourth;
}					t_tetramin;

t_tetramin			**ft_read(char *file, int *t_counter);

#endif
