
#include "ft_select.h"

void	forming_term(t_term **term)
{
	(*term) = (t_term*)malloc(sizeof(t_term));
	(*term)->width_col = 0;
	(*term)->win = (struct winsize*)malloc(sizeof(struct winsize));
	ioctl(0, TIOCGWINSZ, (*term)->win);
	(*term)->oldt = (struct termios*)malloc(sizeof(struct termios));
	(*term)->newt = (struct termios*)malloc(sizeof(struct termios));
	if (tcgetattr(0, (*term)->oldt) == -1)
		return ;
	tcgetattr(0, (*term)->newt);
	(*term)->newt->c_lflag &= ~(ECHO | ICANON);
	(*term)->newt->c_cc[VMIN] = 1;
	(*term)->newt->c_cc[VTIME] = 0;
	(*term)->args = NULL;
	tcsetattr(0, TCSADRAIN, (*term)->newt);
	tputs(tgetstr("vi", NULL), 1, put);
	tputs(tgetstr("ti", NULL), 1, put);
	update_term(term);
}

t_term    *get_term(void)
{
	static t_term *term = NULL;

	if (!term)
		forming_term(&term);
	update_term(&term);
	return (term);
}

void	update_term(t_term **term)
{
	struct winsize winsz;

	ioctl(0, TIOCGWINSZ, &winsz);
	(*term)->win->ws_col = winsz.ws_col;
	(*term)->win->ws_row = winsz.ws_row;
}

void	off_select(t_term *term)
{
	tcsetattr(0, TCSADRAIN, term->oldt);
	tputs(tgetstr("te", NULL), 1, put);
	tputs(tgetstr("ve", NULL), 1, put);
}
