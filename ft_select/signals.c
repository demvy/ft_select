
#include "ft_select.h"

void	handler(int i)
{
	if (i == SIGINT || i == SIGQUIT || i == SIGTERM || i == SIGKILL)
		do_quit();
	else if (i == SIGTSTP)
		do_stop(i);
	else if (i == SIGCONT)
		do_cont(i);
	else if (i == SIGWINCH)
		do_winch();
	else
		ft_putstr_fd("SIGNAL NOT FOUND\n", 2);
}

void	run_signal(void)
{
	int i;

	i = 0;
	while (i < 32)
	{
		signal(i, handler);
		i++;
	}
}

void	pressed_key(char *buf, t_term *term)
{
	if (buf[0] == 27)
		choose_arrow(buf, term);
	else if (buf[0] == 127)
		del_arg(&(term->args));
	else if (buf[0] == 10)
	{
		return_str(term);
		off_select(term);
		exit(0);
	}
	else if (buf[0] == 32)
		select_arg(term->args);
	else if (buf[0] == 4)
		do_quit();
}

void	choose_arrow(char *buf, t_term *term)
{
	if (buf[2] == 68)
		go_to_prev(term);
	else if (buf[2] == 67)
		go_to_next(term);
	else if (buf[2] == 66)
		go_up(term);
	else if (buf[2] == 65)
		go_down(term);
	else if (!buf[1] && !buf[2])
		do_quit();
	if (buf[0] == 27 && buf[1] == 91 &&
		buf[2] == 51 && buf[3] == 126)
		del_arg(&(term->args));
}

void	return_str(t_term *term)
{
	char	*res;
	t_lst_d	*beg;
	t_lst_d	*curr;
	char	*tmp;

	beg = term->args;
	curr = term->args;
	res = ft_strdup("");
	while (curr->next != beg)
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
	ft_putstr_fd(res, 1);
	ft_strdel(&res);
}