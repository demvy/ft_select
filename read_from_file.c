
#include "fillit.h"
#include "libft.h"

#define BUF_SIZE 21

t_coord 	*create_square(int x, int y)
{
	t_coord *new;

	new = malloc(sizeof(t_coord));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	// new->down = down;
	// new->right = right;
	return (new);
}

t_tetramin 	*crea_te(char l)
{
	t_tetramin *new;

	new = malloc(sizeof(t_tetramin));
	if (!new)
		return (NULL);
	new->letter = l;
	// new->first = a;
	// new->second = b;
	// new->third = c;
	// new->fourth = d;
	return (new);
}

void 		print_tetra(t_tetramin *tetramin)
{
	printf("letter = %c \n", tetramin->letter);
	printf("first square: x_coord = %d, y_coord = %d\n", tetramin->first->x, tetramin->first->y);
	printf("sec square: x_coord = %d, y_coord = %d\n", tetramin->second->x, tetramin->second->y);
	printf("third square: x_coord = %d, y_coord = %d\n", tetramin->third->x, tetramin->third->y);
	printf("fourth square: x_coord = %d, y_coord = %d\n\n", tetramin->fourth->x, tetramin->fourth->y);
}

void		is_in_tetramin(char *str, int pos, int *nb_count)
{
	if (pos == 0)
		*nb_count += (str[pos + 1] == '#') + (str[pos + 5] == '#');
	else if (pos == 18)
		*nb_count += (str[pos - 1] == '#') + (str[pos - 5] == '#');
	else if (pos >=1 && pos <= 3)
		*nb_count += (str[pos + 1] == '#') + (str[pos + 5] == '#') +
							(str[pos - 1] == '#');
	else if (pos >= 15 && pos <= 17)
		*nb_count += (str[pos + 1] == '#') + (str[pos - 5] == '#') +
							(str[pos - 1] == '#');
	else
		*nb_count += (str[pos + 1] == '#') + (str[pos - 5] == '#') +
							(str[pos - 1] == '#') + (str[pos + 5] == '#');
}

void		ft_print_square(t_coord *data)
{
	printf("x_coord - %d\t y_coord - %d\n", data->x, data->y);
}

void 		which_tetramin(int counter, t_tetramin **tetramin, t_coord *sq)
{
	if (counter == 1)
		(*tetramin)->first = sq;
	else if (counter == 2)
		(*tetramin)->second = sq;
	else if (counter == 3)
		(*tetramin)->third= sq;
	else if(counter == 4)
		(*tetramin)->fourth = sq;
}

t_tetramin **reading(char *str, int *j)
{
	int			fd;
	int			ret;
	char		*buf;
	int			i;
	t_tetramin 	**arr;
	int 		counter;
	t_coord    *square;
	int nb_count;
	t_tetramin *tetramin;

	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf)
		return (NULL);
	arr = (t_tetramin**)malloc(sizeof(t_tetramin*) * 26);
	if (!arr)
		return (NULL);
	*j = 0;
	if (str)
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			//ft_putstr("open error");
			exit(1);
		}
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			if (ret >= 20)
			{
				buf[ret] = '\0';
//				printf("%s\n", buf);
				i = 0;
				nb_count = 0;
				counter = 0;
				while (buf[i] != '\0'){
					if (buf[i] == '#')
					{
						counter += 1;
						is_in_tetramin(buf, i, &nb_count);
					}
					i++;
				}
				//printf("%d\n", nb_count);
				if ((nb_count == 6 || nb_count == 8) && counter == 4)
				{
					i = 0;
					tetramin = crea_te(*j + 'A');
					counter = 0;
					while (buf[i])
					{
						if (buf[i] == '#')
						{
							square = create_square(i / 5, i % 5);
							//ft_print_square(square);
							counter++;
							which_tetramin(counter, &tetramin, square);
						}
						i++;
					}
					arr[*j] = tetramin;
					//print_tetra(tetramin);
					//free(tetramin);
				}
				else
					exit(1);
				*j = *j + 1;
			}
		}
		close(fd);
		free(buf);
	}
	return (arr);
}

void		print_arr_tetra(t_tetramin **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		//printf("%s\n", "it worked");
		print_tetra(arr[i]);
		i++;
	}
}

int 		ft_sqrt(int a)
{
	int temp;

	temp = 1;
	while (temp * temp < a)
		temp++;
	return (temp);
}

int 		field_size(int length)
{
	return (ft_sqrt(4 * length));
}
/*
void		ft_put_tetramin(char* tab, t_tetramin *arr, int pos, int size)
{
	char	l;

	printf("pos = %d\n", pos);
	if (tab[pos] == '.' &&
		tab[pos + ((arr->second)->x_coord - (arr->first)->x_coord) * (size + 1) +
	 ((arr->second)->y_coord - (arr->first)->y_coord)] == '.' &&
	 tab[pos + ((arr->third)->x_coord - (arr->first)->x_coord) * (size + 1) +
	 ((arr->third)->y_coord - (arr->first)->y_coord)] == '.' &&
	 tab[pos + ((arr->fourth)->x_coord - (arr->first)->x_coord) * (size + 1) +
	 ((arr->fourth)->y_coord - (arr->first)->y_coord)] == '.')
	{
		printf("yes\n");

		l = arr->letter;
		tab[pos] = l;
		tab[pos + ((arr->second)->x_coord - (arr->first)->x_coord) * (size + 1) +
	 ((arr->second)->y_coord - (arr->first)->y_coord)] = l;
	 tab[pos + ((arr->third)->x_coord - (arr->first)->x_coord) * (size + 1) +
	 ((arr->third)->y_coord - (arr->first)->y_coord)] = l;
	 tab[pos + ((arr->fourth)->x_coord - (arr->first)->x_coord) * (size + 1) +
	 ((arr->fourth)->y_coord - (arr->first)->y_coord)] = l;
	 printf("new tab - \n%s\n", tab);
	}
	else if (pos <= size * (size + 1))
	{
		printf("current pos = %d\n", pos);
		ft_put_tetramin(tab, arr, pos + 1, size);
	}
}
*/

int			ft_paste_tetramin(char* tab, t_tetramin **arr, int pos, int size, int j)
{
//	int 	pos;
	char	l;

//	pos = 0;
//	while (*tab || *tab != '.')
//		pos++;
	// print_tetra(arr[j]);
	// printf("tab1 = \n%s\npos - %d\n", tab, pos);
	// printf("x1 = %d\n", pos + ((arr[j]->second)->x - (arr[j]->first)->x) * (size + 1) +
	//  ((arr[j]->second)->y - (arr[j]->first)->y));
	// printf("x2 = %d\n", pos + ((arr[j]->third)->x - (arr[j]->first)->x) * (size + 1) +
	//  ((arr[j]->third)->y - (arr[j]->first)->y));
	// printf("x3 = %d\n", pos + ((arr[j]->fourth)->x - (arr[j]->first)->x) * (size + 1) +
	//  ((arr[j]->fourth)->y - (arr[j]->first)->y));
	if (tab[pos] == '.' &&
		tab[pos + ((arr[j]->second)->x - (arr[j]->first)->x) * (size + 1) +
	 ((arr[j]->second)->y - (arr[j]->first)->y)] == '.' &&
	 tab[pos + ((arr[j]->third)->x - (arr[j]->first)->x) * (size + 1) +
	 ((arr[j]->third)->y - (arr[j]->first)->y)] == '.' &&
	 tab[pos + ((arr[j]->fourth)->x - (arr[j]->first)->x) * (size + 1) +
	 ((arr[j]->fourth)->y - (arr[j]->first)->y)] == '.')
	{
		// printf("yes\n");
		l = arr[j]->letter;
			tab[pos] = l;
			tab[pos + ((arr[j]->second)->x - (arr[j]->first)->x) * (size + 1) +
		 ((arr[j]->second)->y - (arr[j]->first)->y)] = l;
		 tab[pos + ((arr[j]->third)->x - (arr[j]->first)->x) * (size + 1) +
		 ((arr[j]->third)->y - (arr[j]->first)->y)] = l;
		 tab[pos + ((arr[j]->fourth)->x - (arr[j]->first)->x) * (size + 1) +
		 ((arr[j]->fourth)->y - (arr[j]->first)->y)] = l;
		//tab += pos;
		return (1);
	}
	else
	{
		//printf("no\n");
		return (0);
	}
}

char		*ft_clear_tetramin(char *tab, char c)
{
	char	*tmp;

	tmp = tab;
	while (*tmp)
	{
		if (*tmp == c)
			*tmp = '.';
		tmp++;
	}
	return (tab);
}

int 		ft_find_pos(char *str, char c)
{
	int pos;

	pos = 0;
	while (str[pos] != c && str[pos] != '\0')
		pos++;
	return (pos);
}

int			ft_put_tetramin(char* tab, t_tetramin **arr, int pos, int size, int j, int t_amount)
{
	printf("pos = %d\n", pos);
	printf("tab = \n%s\n", tab);
	printf("current tetramin %d\tcurrent position - %d\n ", j, pos);
	if (j >= t_amount)
	{
		printf("WTF?\n");
		return (1);
	}
	else if ((pos < size * (size + 1) - 5) && ft_paste_tetramin(tab, arr, pos, size, j) == 1)
	{
		printf("paste one OK\tpos = %d\ttetramin - %d\n", pos, j);
		pos = 0;
		while (tab[pos] != '.')
			pos++;
		if (pos > size * (size + 1) - 5)
			return (0);
		if (j + 1 >= t_amount)
			return (1);
		else if (ft_put_tetramin(tab, arr, pos, size, j + 1, t_amount) == 1)
		{
			printf("paste next tetramin OK\tpos = %d\ttetramin - %d\n", pos, j + 1);
			return (1);
		}
		else
		{
			printf("paste next tetramin FALSE\tpos = %d\ttetramin - %d\n", pos, j + 1);
			return (0);
		}
	}
	else 
	{
		printf("paste one FALSE\tpos = %d\ttetramin - %d\ntab = \n%s\n", pos, j, tab);
		pos += 1;
		if (pos < size * (size + 1))
		{
			if (ft_put_tetramin(tab, arr, pos, size, j, t_amount) == 1)
				printf("paste next position OK\tpos = %d\ttetramin - %d\n", pos + 1, j);
			else
			{
				printf("paste next position FALSE\tpos = %d\ttetramin - %d\n", pos + 1, j);
/*				pos += 1;
				if (pos < size * (size + 1))
				{
					printf("paste next  sssssss position OK\tpos = %d\ttetramin - %d\n", pos + 1, j);
					ft_put_tetramin(tab, arr, pos + 1, size, j);
					
				}*/
				return (0);
			}
			return (1);
		}
		else
		{
			printf("try to clear\ttetramin - %d\told tab:\n%s\n", j, tab);
			pos = ft_find_pos(tab, arr[j - 1]->letter);
			if (pos < size * (size + 1) - 5)
			{
				tab = ft_clear_tetramin(tab, arr[j - 1]->letter);
				printf("new pos - %d\nnewest tab:\n%s\n",pos + 1, tab);
				ft_put_tetramin(tab, arr, pos + 1, size, j - 1, t_amount);
			}
			else
				return	(0);
		}
		return (0);
	}
	// {
	// 	printf("current pos = %d\n", pos);
	// 	if (ft_put_tetramin(tab, arr, pos + 1, size, j) == 1)
	// 		ft_put_tetramin(tab, arr, pos + 1, size, j + 1);
	// }
}

void		ft_build_matrix(int size, t_tetramin **arr, int t_amount)
{
	char	*tab;
	int 	len;
	int		i;
	int		j; // counter for arr;


	len = size * (size + 1);
	if ((tab = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		exit (1);
	tab[len] = '\0';
	i = 1;
	tab = (char*)ft_memset(tab, '.', len);
	while (tab[i - 1] != '\0')
	{
		if (i % (size + 1) == 0)
			tab[i - 1] = '\n';
		i++;
	}
	i = 1;
	j = 0;
/*	while (tab[i - 1] != '\0' && j < t_amount)
	{
		if (tab[i - 1] == '#' || tab[i] == '\n')
			continue ;
			;
		if (tab[i - 1] == '.')
		{
			printf("tab start - \n%s\n", tab);*/
	printf("START FILL TETRAMIN\n");
			//ft_put_tetramin(tab, arr[j++], i - 1, size);
	ft_put_tetramin(tab, arr, i - 1, size, j, t_amount);
/*		}
		printf("i = %d\tj = %d\n, tab = \n%s\n", i, j, tab);
		i++;
		printf("i = %d\tj = %d\n, tab = \n%s\n", i, j, tab);
	}*/
	printf("len = %d\ntab = \n%s\n", len, tab);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		exit(1);
	t_tetramin **arr;
	int length;

	arr = reading(argv[1], &length);
//	print_arr_tetra(arr);
	printf("len = %d\n", length);
	int p = field_size(length);
	printf("square size - %d\n", p);
	//	printf("%s\n", "succss");
//	print_arr_tetra(arr);
	ft_build_matrix(p, arr, length);
}
