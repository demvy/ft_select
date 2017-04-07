<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:01:52 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/04/07 13:01:58 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		select_arg(t_lst_d *lst)
{
	t_lst_d	*first;
	t_lst_d	*curr;
=======
//
// Created by Valeriy Demeshko on 3/20/17.
//

#include "ft_select.h"

void    select_arg(t_lst_d *lst)
{
	t_lst_d *first;
	t_lst_d *curr;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3

	first = lst;
	curr = lst;
	while (!curr->curs)
		curr = curr->next;
	if (curr->selected)
		curr->selected = 0;
	else
		curr->selected = 1;
	curr->next->curs = 1;
	curr->curs = 0;
}

<<<<<<< HEAD
void		go_to_prev(t_term *term)
{
	t_lst_d	*first;
	t_lst_d	*curr;
=======
void    go_to_prev(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3

	first = term->args;
	curr = term->args;
	while (!curr->curs)
		curr = curr->next;
	if (curr->curs)
	{
		curr->curs = 0;
		curr->prev->curs = 1;
	}
}

<<<<<<< HEAD
void		go_to_next(t_term *term)
{
	t_lst_d	*first;
	t_lst_d	*curr;
=======
void    go_to_next(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3

	first = term->args;
	curr = term->args;
	while (!curr->curs)
		curr = curr->next;
	if (curr->curs)
	{
		curr->curs = 0;
		curr->next->curs = 1;
	}
}

<<<<<<< HEAD
void		go_up(t_term *term)
{
	t_lst_d	*first;
	t_lst_d	*curr;
	size_t	cols;
=======
void    go_up(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
	size_t  cols;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3

	first = term->args;
	curr = term->args;
	while (!curr->curs && curr != first)
		curr = curr->next;
	cols = term->win->ws_col / (term->width_col + 5);
	while (cols > 0)
	{
		go_to_prev(term);
		cols--;
	}
}

<<<<<<< HEAD
void		go_down(t_term *term)
{
	t_lst_d	*first;
	t_lst_d	*curr;
	size_t	cols;
=======
void    go_down(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
	size_t  cols;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3

	first = term->args;
	curr = term->args;
	while (!curr->curs && curr != first)
		curr = curr->next;
	cols = term->win->ws_col / (term->width_col + 5);
	while (cols > 0)
	{
		go_to_next(term);
		cols--;
	}
<<<<<<< HEAD
}
=======
}
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
