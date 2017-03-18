
#include "ft_select.h"

void	forming_shell(t_term *term)
{
	term = (t_term*)malloc(sizeof(t_term));
	term->width_col = 0;
	term->win = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, term->win);
	term->oldt = (termios*)malloc(sizeof(termios));
	term->newt = (termios*)malloc(sizeof(termios));
	tcgetattr(0, term->newt);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 0;
	term.c_cc[VTIME] = 0;
	tcsettatr(0, TCSADRAIN, term->newt);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_fd);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_fd);
	update_term(term);
}

void	update_term(t_term *term)
{
	struct winsize winsz;

	ioctl(0, TIOCGWINSZ, &winsz);
	shell->win->ws_col = winsz.ws_col;
	shell->win->ws_row = winsz.ws_row;
}

void	off_select(t_term *term)
{
	tcsettatr(0, TCSADRAIN, term->oldt);
	tputs(tgetstr("te", NULL), 1, ft_putchar_fd);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_fd);
}