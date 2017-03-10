
#include "ft_select.h"

int		ft_do()
{
	char *buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (ft_strchr(buffer, 27) != NULL)
			printf("C'est une fleche !\n");
    	else if (ft_strchr(buffer, 4) != NULL)
    	{
      		printf("Ctlr+d, on quitte !\n");
      		return (0);
      	}
	}
	return (0);
}

int		main(int ac, char **av, char **env)
{
	char			*name_term;
	struct termis	term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	/*
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
		*/
	ft_do();
	return (0);
}
