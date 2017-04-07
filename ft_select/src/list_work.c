
#include "ft_select.h"

void	inside_parse(char *command, t_lst_d **lst, unsigned int *i)
{
	size_t len;
	char	*tmp;

	if (command[*i] == '\"')
	{
		len = ft_substrlen((command + *i + 1), '\"');
		tmp = ft_strsub(command, *i + 1, len);
		add_el(lst, tmp);
		*i += len + 2;
		free(tmp);
	}
	else if (command[*i] != ' ')
	{
		len = ft_substrlen((command + *i), ' ');
		tmp = ft_strsub(command, *i, len);
		add_el(lst, tmp);
		*i += len;
		free(tmp);
	}
	else
		(*i)++;
}

void	parse_command(char *command, t_lst_d **lst)
{
	unsigned int	i;

	i = 0;
	change_str(command);
	while (command[i] != '\0')
	{
		inside_parse(command, lst, &i);
	}
}
/*
void	args_lst_delone(t_lst_d **lst)
{
	free((*lst)->data);
	free(*lst);
	*lst = NULL;
}

void	args_free_lst(t_lst_d *lst)
{
	if (lst != NULL)
	{
		if (lst->next != NULL)
			args_free_lst(lst->next);
		args_lst_delone(&lst);
	}
}
*/
/*void	add_el(t_lst_d **lst, char *arg)
{
	t_lst_d *beg;
	t_lst_d *new;
	
	if ((*lst) == NULL)
	{
		*lst = (t_lst_d*)malloc(sizeof(t_lst_d));
		(*lst)->data = ft_strdup(arg);
		(*lst)->next = NULL;
	}
	else
	{
		beg = *lst;
		while (beg->next != NULL)
			beg = beg->next;
		new = (t_lst_d*)malloc(sizeof(t_lst_d));
		new->data = ft_strdup(arg);
		new->next = NULL;
		beg->next = new;
	}
}*/
