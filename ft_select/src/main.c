
#include "ft_select.h"

int		ft_do()
{
	char buffer[3];

	while (1)
	{
		//ft_printf("$>");
		read(0, buffer, 3);
		if (buffer[0] == 27)
			ft_printf("C'est une fleche !\n");
    	else if (buffer[0] == 4)
    	{
      		ft_printf("Ctlr+d, on quitte !\n");
      		return (0);
      	}
      	else
      		ft_printf(buffer);
      	ft_bzero(buffer, 3);
	}
	return (0);
}

int		main(void)
{
	char			*name_term;
	struct termios	term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == -11)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
		
	ft_do();
	return (0);
}
