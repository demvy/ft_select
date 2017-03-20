
#include "ft_select.h"


void	in_main(char **av)
{
	char	buf[4];
	t_term	*term;

	run_signal();
	term = NULL;
	forming_term(term);
	get_lst_args(av, term);
	while (1)
	{
		tputs(tgetstr("cl", NULL), 1, &put);
		pressed_key(buf, term);
		
	}
}

int		ft_do()
{
	char buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			ft_printf("Ctlr+d, on quitte !\n");
			return (0);
		}
		else if (buffer[0] == 12)
		{
			ft_printf("Ctlr+L!!!!\n");
			return (0);
		}
		else
			ft_printf(buffer);
		ft_bzero(buffer, 3);
	}
	return (0);
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
	
//	term.c_lflag &= ~(ECHO | ICANON);
//	term.c_cc[VMIN] = 0;
//	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	(void)ac;
	in_main(av);
	//ft_do();
	return (0);
}
