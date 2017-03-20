//
// Created by valeriy on 18.03.17.
//

#include "ft_select.h"

void do_quit()
{
	t_term *term;

	term = get_term();
	off_select(term);
	exit(0);
}

void do_stop(int i)
{
	(float)i;
	signal(SIGTSTP, SIG_DFL);
	off_select(get_term());
}

void do_cont(int i)
{
	t_term *term;

	(float)i;
	term = get_term();
	signal(SIGTSTP, do_stop);
	signal(SIGCONT, do_cont);
	tcsetattr(0, TCSADRAIN, term->newt);
	tputs(tgetstr("vi", NULL), 1, put);
	tputs(tgetstr("ti", NULL), 1, put);
	tputs(tgetstr("cl", NULL), 1, put);
	show_args(term);
}

void do_winch()
{
	t_term *term;

	term = get_term();
	update_term(term);
	tputs(tgetstr("cl", NULL), 1, put);
	show_args(term);
}