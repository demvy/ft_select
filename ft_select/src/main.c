
#include "ft_select.h"

void	in_main(char **av)
{
	char	buf[4];
	t_term	*term;

	term = get_term();
	get_lst_args(av, term);
	run_signal();
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, put);
		pressed_key(buf, term);
		show_args(term);
		ft_bzero(buf, 4);
		read(0, buf, 4);
		update_term(&term);
	}
	return ;
}

int		main(int ac, char **av)
{
	char			*name_term;
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("NOT ENVIRONMENT VAR TERM!\n", 2);
		return (-1);
	}
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	if (ac == 1)
	{
		ft_putstr_fd("NO ARGUMENTS PASSED!\n", 2);
		return (-1);
	}
//	term.c_lflag &= ~(ECHO | ICANON);
//	term.c_cc[VMIN] = 0;
//	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	(void)ac;
	in_main(av);
	return (0);
}
