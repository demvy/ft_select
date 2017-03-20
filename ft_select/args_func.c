
#include "ft_select.h"

void	get_lst_args(char **av, t_term *term)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		add_el(&(term->args), av[i]);
		i++;
	}
}

t_lst_d	*new_arg(char *s)
{
	t_lst_d *new;

	new = (t_lst_d*)malloc(sizeof(t_lst_d));
	new->data = ft_strdup(s);
	new->next = NULL;
	new->prev = NULL;
	new->curs = 0;
	new->selected = 0;
	return (new);
}

void	add_el(t_lst_d **lst, char *arg)
{
	t_lst_d *beg;
	t_lst_d *new;
	t_lst_d *curr;
	//ft_printf("%s\n", arg);
	if ( (*lst) == NULL)
	{
		*lst = new_arg(arg);
		(*lst)->next = (*lst);
		(*lst)->prev = (*lst);
		(*lst)->curs = 1;
	}
	else
	{
		curr = *lst;
		beg = *lst;
		while (curr->next != NULL && curr->next != beg)
			curr = curr->next;
		new = new_arg(arg);
		new->next = beg;
		new->prev = curr;
		curr->next = new;
	}
}

void	del_arg(t_lst_d **lst)
{
	//t_lst_d	*first;
	t_lst_d	*curr;
	t_lst_d	*pre;

	//first = *lst;
	curr = *lst;
	while (!curr->curs)
	{
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
	(curr->next)->prev = pre;
	ft_strdel(&(curr->data));
	free(curr->next);
	curr->next = NULL;
	free(curr->prev);
	curr->prev = NULL;
	free(curr);
	curr = NULL;
}