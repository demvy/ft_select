
#include "fillit.h"
#include "libft.h"

#define BUF_SIZE 21

t_square 	*create_square(int x, int y)
{
	t_square *new;

	new = malloc(sizeof(t_square));
	if (!new)
		return (NULL);
	new->x_coord = x;
	new->y_coord = y;
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
	printf("first square: x_coord = %d, y_coord = %d\n", tetramin->first->x_coord, tetramin->first->y_coord);
	printf("sec square: x_coord = %d, y_coord = %d\n", tetramin->second->x_coord, tetramin->second->y_coord);
	printf("third square: x_coord = %d, y_coord = %d\n", tetramin->third->x_coord, tetramin->third->y_coord);
	printf("fourth square: x_coord = %d, y_coord = %d\n\n", tetramin->fourth->x_coord, tetramin->fourth->y_coord);
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

void		ft_print_square(t_square *data)
{
	printf("x_coord - %d\t y_coord - %d\n", data->x_coord, data->y_coord);
}

void 		which_tetramin(int counter, t_tetramin **tetramin, t_square *sq)
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
	t_square    *square;
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
				printf("%s\n", buf);
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

void		ft_put_tetramin(char* tab, t_tetramin *arr, int pos, int size)
{
	char	l;

	if (tab[pos + ((arr->second)->x_coord - (arr->first)->x_coord) * (size + 1) +
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
	else
		ft_put_tetramin(tab, arr, pos + 1, size);
}

void		ft_build_matrix(int size, t_tetramin **arr, int t_amount)
{
	char	*tab;
	int 	len;
	int		i;


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
	while (tab[i - 1] != '\0')
	{
		if (tab[i - 1] == '#' || tab[i] == '\n')
			continue ;
		if (tab[i - 1] == '.')
		{
			printf("tab start - \n%s\n", tab);
			printf("lohi\n");
			ft_put_tetramin(tab, arr[i - 1], i - 1, size);
		}
		i++;
	}
	printf("len = %d\ntab = \n%s\n", len, tab);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		exit(1);
	t_tetramin **arr;
	int length;

	arr = reading(argv[1], &length);
	int p = field_size(length);
	printf("%d\n", p);
	//	printf("%s\n", "succss");
	print_arr_tetra(arr);
	ft_build_matrix(p, arr, length);
}
