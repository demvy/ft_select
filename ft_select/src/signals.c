
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
	if (buf[0] == '\033')
		choose_arrow(buf, term);
	else if (buf[0] == 32)
		select_arg(term->args);
	else if (buf[0] == 127 || buf[0] == 8)
	{
		ft_printf("ccccccc\n");
		sleep(2);
		term->args = del_arg(&(term->args));
		show_args(term);
		ft_printf("wwwwwwwww\n");
		sleep(3);
	}
	else if (buf[0] == 13 || buf[0] == 10)
		return_str(term);
	else if (buf[0] == 4 || buf[0] == 27)
		do_quit();
}

void	choose_arrow(char *buf, t_term *term)
{
	if (buf[2] == 68)
		go_to_prev(term);
	else if (buf[2] == 67)
		go_to_next(term);
	else if (buf[2] == 66)
		go_down(term);
	else if (buf[2] == 65)
		go_up(term);
	//if (buf[0] == '\033' && buf[1] == '[' &&
	//	buf[2] == 51 && buf[3] == 126)
	//	del_arg(&(term->args));
}

void	return_str(t_term *term)
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
	ft_printf("%s\n", res);
	ft_strdel(&res);
	exit(0);
}