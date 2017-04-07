<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:02:35 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/04/07 13:02:36 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		handler(int i)
{
	if (i == SIGTSTP)
		do_stop();
	else if (i == SIGCONT)
		do_cont();
=======

#include "ft_select.h"

void	handler(int i)
{
	if (i == SIGTSTP)
		do_stop(i);
	else if (i == SIGCONT)
		do_cont(i);
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
	else if (i == SIGINT || i == SIGQUIT || i == SIGTERM || i == SIGKILL)
		do_quit();
	else if (i == SIGWINCH)
		do_winch();
	else
		ft_putstr_fd("SIGNAL NOT FOUND\n", 0);
}

<<<<<<< HEAD
void		run_signal(void)
=======
void	run_signal(void)
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	signal(SIGWINCH, handler);
	signal(SIGINT, handler);
	signal(SIGKILL, handler);
	signal(SIGTERM, handler);
	signal(SIGQUIT, handler);
	signal(SIGTSTP, handler);
	signal(SIGCONT, handler);
}

<<<<<<< HEAD
void		pressed_key(char *buf, t_term *term)
=======
void	pressed_key(char *buf, t_term *term)
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	if (buf[0] == '\033')
		choose_arrow(buf, term);
	else if (buf[0] == 32)
		select_arg(term->args);
	else if (buf[0] == 127 || buf[0] == 8)
		del_arg(&(term->args));
	else if (buf[0] == 13 || buf[0] == 10)
		return_str(term);
<<<<<<< HEAD
}

void		choose_arrow(char *buf, t_term *term)
=======
	else if (buf[0] == 4)
		do_quit();
}

void	choose_arrow(char *buf, t_term *term)
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	if (buf[2] == 68)
		go_to_prev(term);
	else if (buf[2] == 67)
		go_to_next(term);
	else if (buf[2] == 66)
		go_down(term);
	else if (buf[2] == 65)
		go_up(term);
<<<<<<< HEAD
	else if (buf[0] == '\033' && buf[1] == '[' &&
			buf[2] == 51 && buf[3] == 126)
		del_arg(&(term->args));
	else if (buf[0] == '\033' && buf[1] == '\0')
		do_quit();
}

void		return_str(t_term *term)
=======
	if (buf[0] == '\033' && buf[1] == '[' &&
		buf[2] == 51 && buf[3] == 126)
		del_arg(&(term->args));
}

void	return_str(t_term *term)
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
{
	char	*res;
	int		i;
	t_lst_d	*curr;
	char	*tmp;

	i = list_size(term->args);
	curr = term->args;
	res = ft_strdup("");
	while (i-- > 0)
	{
		if (curr->selected)
		{
			tmp = ft_strjoin(res, curr->data);
			ft_strdel(&res);
			res = ft_strjoin(tmp, " ");
			ft_strdel(&tmp);
		}
		curr = curr->next;
	}
	off_select(term);
	res[ft_strlen(res) - 1] = '\0';
<<<<<<< HEAD
	ft_printf("%s", res);
	ft_strdel(&res);
	exit(0);
}
=======
	ft_printf("%s\n", res);
	ft_strdel(&res);
	exit(0);
}
>>>>>>> 33da2df41d08575330555533162a7c1fc4d21af3
