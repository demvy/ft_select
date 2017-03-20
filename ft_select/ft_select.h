
#ifndef _FT_SELECT_H_
# define _FT_SELECT_H_

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <signal.h>

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
	size_t	    	width_col;
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


void	forming_term(t_term *term);
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
int     put(int c);
void	del_arg(t_lst_d **lst);
void    do_quit();
void    do_stop(int i);
void    do_cont(int i);
void do_winch();
t_term  *get_term(void);
void    show_args(t_term *term);
size_t  max_len(t_lst_d *lst);
void    print_arg(t_lst_d *el, t_term *term);
size_t  list_size(t_lst_d *lst);
void    select_arg(t_lst_d *lst);
void    go_to_prev(t_term *term);
void    go_to_next(t_term *term);
void    go_up(t_term *term);
void    go_down(t_term *term);


void	in_main(char **av);

#endif