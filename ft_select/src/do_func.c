<<<<<<< HEAD
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
=======
//
// Created by valeriy on 18.03.17.
//

#include "ft_select.h"

void do_quit()
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	off_select(get_term());
	exit(0);
}

<<<<<<< HEAD
void		do_stop(void)
{
	char	cp[2];
	t_term	*term;

	term = get_term();
	cp[0] = term->oldt->c_cc[VSUSP];
	cp[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	off_select(term);
	ioctl(0, TIOCSTI, cp);
}

void		do_cont(void)
{
	t_term	*term;

=======
void do_stop(int i)
{
	(void)i;
	signal(SIGTSTP, SIG_DFL);
	off_select(get_term());
}

void do_cont(int i)
{
	t_term *term;

	(void)i;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
	term = get_term();
	signal(SIGTSTP, do_stop);
	signal(SIGCONT, do_cont);
	tcsetattr(0, TCSADRAIN, term->newt);
	tputs(tgetstr("vi", NULL), 1, put);
	tputs(tgetstr("ti", NULL), 1, put);
	tputs(tgetstr("cl", NULL), 1, put);
	show_args(term);
}

<<<<<<< HEAD
void		do_winch(void)
{
	t_term	*term;
=======
void do_winch()
{
	t_term *term;
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3

	term = get_term();
	update_term(&term);
	tputs(tgetstr("cl", NULL), 1, put);
	show_args(term);
<<<<<<< HEAD
}
=======
}
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
