/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshudria <oshudria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:58:04 by oshudria          #+#    #+#             */
/*   Updated: 2016/12/19 10:13:12 by oshudria         ###   ########.fr       */
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

typedef struct		s_square
{
	char			*str;
	int				size;
}					t_square;

t_tetramin			**ft_read(char *file, int *t_counter);
t_square			*ft_build_matrix(t_square *map, int t_amount);
//void 				ft_clear(char *tab, char c);
int					ft_check_free_space(t_square *map, int last_elem);
//
//int					ft_correct_position(int pos, char *str, int size);
//int					ft_is_good_place(int pos, char *str, int size, int mode);
//
int					ft_solve(t_square *map, t_tetramin **t_tab, int i, int n);

#endif
