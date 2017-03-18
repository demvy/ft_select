
#ifndef _FT_SELECT_H_
# define _FT_SELECT_H_

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
#include <sys/ioctl.h>

typedef struct		s_lst_d
{
    char			*data;
    struct s_lst_d	*next;
    struct s_lst_d	*prev;
    int				selected;
    int				curs;
}					t_lst_d;


typedef struct 		s_term
{
	int				width_col;
	struct winsize	*win;
	struct termios	*oldt;
	struct termios	*newt;
	struct s_lst_d	*args;
}					t_term;


void	parse_command(char *command, t_lst_d **lst);
void	args_lst_delone(t_lst_d **lst);
void	args_free_lst(t_lst_d *lst);
void	add_el(t_lst_d **lst, char *arg);
void	change_str(char *s);
size_t	ft_substrlen(const char *s, char c);
void	inside_parse(char *command, t_lst_d **lst, unsigned int *i);


void	forming_shell(t_term *term);
void	get_lst_args(char **av, t_term *term);
void	update_term(t_term *term);
void	off_select(t_term *term);
t_lst_d	*new_arg(char *s);
void	add_el(t_lst_d **lst, char *arg);
void	handler(int i);
void	run_signal(void);
void	return_str(t_term *term);
void	pressed_key(char *buf, t_term *term);
void	choose_arrow(char *buf, t_term *term);


#endif