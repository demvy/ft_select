//
// Created by Valeriy Demeshko on 3/20/17.
//

#include "ft_select.h"

void    select_arg(t_lst_d *lst)
{
	t_lst_d *first;
	t_lst_d *curr;

	first = lst;
	curr = lst;
	while (curr != first && !curr->curs)
		curr = curr->next;
	if (curr->selected)
		curr->selected = 0;
	else
		curr->selected = 1;
	curr->next->curs = 1;
	curr->curs = 0;
}

void    go_to_prev(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;

	first = term->args;
	curr = term->args;
	while (!curr->curs && curr != first)
		curr = curr->next;
	if (curr->curs)
	{
		curr->curs = 0;
		curr->prev->curs = 1;
	}
}

void    go_to_next(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;

	first = term->args;
	curr = term->args;
	while (!curr->curs && curr != first)
		curr = curr->next;
	if (curr->curs)
	{
		curr->curs = 0;
		curr->next->curs = 1;
	}
}

void    go_up(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
	size_t  cols;

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

void    go_down(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
	size_t  cols;

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
}