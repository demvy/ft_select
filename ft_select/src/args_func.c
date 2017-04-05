
#include "ft_select.h"

void	get_lst_args(char **av, t_term *term)
{
	int	i;

	i = 1;
	while (av[i] != NULL)
	{
		//ft_printf("here %d\n", i);
		//printf("%zu\n", term->width_col);
		//printf("%p\n", term->args);

		add_el(term, av[i]);
		//ft_printf("ddddd\n");
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

void	add_el(t_term *lst, char *arg)
{
	t_lst_d *beg;
	t_lst_d *new;
	t_lst_d *curr;

	if (!lst->args)
	{
		lst->args = new_arg(arg);
		(lst->args)->next = (lst->args);
		(lst->args)->prev = (lst->args);
		(lst->args)->curs = 1;
	}
	else
	{
		curr = lst->args;
		beg = lst->args;
		while (curr->next != NULL && curr->next != beg)
			curr = curr->next;
		new = new_arg(arg);
		new->next = beg;
		new->prev = curr;
		beg->prev = new;
		curr->next = new;
	}
}

// static void	print_lst(t_lst_d *lst)
// {
// 	//int i = list_size(lst);
// 	t_lst_d *curr;
// 	t_lst_d *sec;
// 	t_lst_d *th;
// 	t_lst_d *fou;

// 	curr = lst;
// 	ft_printf("cur===%s\n", curr->data);
// 	sec = curr->next;
// 	ft_printf("sec===%s\n", sec->data);
// 	th = sec->next;
// 	ft_printf("th==%s\n", th->data);
// 	fou = th->next;
// 	ft_printf("fou===%s\n", fou->data);
// 	//ft_printf("i=%d\n", i);
// 	//while (i-- > 0)
// 	//{
// 	//	ft_printf("data=%s\n", curr->data);
// 	//	curr = curr->next;
// 	//}
// }

void	del_arg(t_lst_d **lst)
{
	t_lst_d	*first;
	t_lst_d	*curr;
	t_lst_d	*pre;

	first = *lst;
	curr = *lst;
	pre = (*lst)->prev;
	while (!(curr->curs))
	{
		pre = pre->next;
		curr = curr->next;
	}
	if (list_size(first) == 1)
	{
		ft_strdel(&(first->data));
		do_quit(0);
	}
	if (curr == first)
		*lst = curr->next;
	pre->next = (curr->next);
	(curr->next)->prev = pre;
	(curr->next)->curs = 1;
	ft_strdel(&(curr->data));
	free(curr);
	curr = NULL;
}
