//
// Created by valeriy on 19.03.17.
//

#include "ft_select.h"

void    print_arg(t_lst_d *el, t_term *term)
{
	if (el->curs)
		tputs(tgetstr("us", NULL), 1, put);
	if (el->selected)
		tputs(tgetstr("mr", NULL), 1, put);
	ft_printf("\e[38;5;27m%-*s", term->width_col + 5, el->data);
	if (el->selected)
		tputs(tgetstr("me", NULL), 1, put);
	if (el->curs)
		tputs(tgetstr("ue", NULL), 1, put);
}

void    show_args(t_term *term)
{
	t_lst_d *first;
	t_lst_d *curr;
	size_t  cols;
	size_t  i;

	first = term->args;
	curr = term->args;
	//ft_putstr(term->args->data);
	term->width_col = max_len(term->args);
	//printf("width_col = %zu\n", term->width_col);
	//printf("%hu\n", term->win->ws_col);
	cols = term->win->ws_col / (term->width_col + 5);
	//printf("cols = %zu\n", cols);
	if ((list_size(term->args) / cols) > term->win->ws_row)
	{
		ft_printf(STDIN_FILENO, "Not enought size\n");
		return ;
	}
	while (curr)
	{
		i = 0;
		while (i < cols)
		{
			print_arg(curr, term);
			i++;
			curr = curr->next;
			if (curr == first)
				break;
			ft_printf(" ");
		}
		if (curr == first)
			break;
		ft_printf("\n");
		//tputs(tgetstr("nw", NULL), 1, put);
	}
	//ft_printf("chlen\n");
}