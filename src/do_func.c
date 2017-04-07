/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:59:59 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/04/07 13:00:03 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		do_quit(void)
{
	off_select(get_term());
	exit(0);
}

void		do_stop(int i)
{
	char	cp[2];
	t_term	*term;

	term = get_term();
	cp[0] = term->oldt->c_cc[VSUSP];
	cp[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	off_select(term);
	ioctl(0, TIOCSTI, cp);
	(void)i;
}

void		do_cont(int i)
{
	t_term	*term;

	term = get_term();
	signal(SIGTSTP, do_stop);
	signal(SIGCONT, do_cont);
	tcsetattr(0, TCSADRAIN, term->newt);
	tputs(tgetstr("vi", NULL), 1, put);
	tputs(tgetstr("ti", NULL), 1, put);
	tputs(tgetstr("cl", NULL), 1, put);
	show_args(term);
	(void)i;
}

void		do_winch(void)
{
	t_term	*term;

	term = get_term();
	update_term(&term);
	tputs(tgetstr("cl", NULL), 1, put);
	show_args(term);
}
