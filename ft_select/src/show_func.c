<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:02:14 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/04/07 13:02:16 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_arg(t_lst_d *el, t_term *term)
=======
//
// Created by valeriy on 19.03.17.
//

#include "ft_select.h"

void    print_arg(t_lst_d *el, t_term *term)
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	if (el->curs)
		tputs(tgetstr("us", NULL), 1, put);
	if (el->selected)
		tputs(tgetstr("mr", NULL), 1, put);
	ft_printf_fd(0, "\e[38;5;27m%-*s", term->width_col + 5, el->data);
	if (el->selected)
		tputs(tgetstr("me", NULL), 1, put);
	if (el->curs)
		tputs(tgetstr("ue", NULL), 1, put);
}

<<<<<<< HEAD
static int	in_show_args(t_lst_d *first, t_lst_d *curr, size_t cols, t_term *t)
=======
static int in_show_args(t_lst_d *first, t_lst_d *curr, size_t cols, t_term *t)
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	size_t	i;

	while (curr)
	{
		i = 0;
		while (i < cols)
		{
			print_arg(curr, t);
			i++;
			curr = curr->next;
			if (curr == first)
<<<<<<< HEAD
				break ;
			ft_printf_fd(0, " ");
		}
		if (curr == first)
			break ;
=======
				break;
			ft_printf_fd(0, " ");
		}
		if (curr == first)
			break;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
		ft_printf_fd(0, "\n");
	}
	return (0);
}

<<<<<<< HEAD
void		show_args(t_term *term)
{
	t_lst_d	*first;
	t_lst_d	*curr;
	size_t	cols;

=======
void    show_args(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
	size_t  cols;
	
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
	first = term->args;
	curr = term->args;
	term->width_col = max_len(term->args);
	cols = term->win->ws_col / (term->width_col + 5);
	if (cols == 0 || (list_size(term->args) / cols) > term->win->ws_row)
	{
		ft_putstr_fd("Not enought size\n", 0);
		return ;
	}
	in_show_args(first, curr, cols, term);
<<<<<<< HEAD
}
=======
}
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
