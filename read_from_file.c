
#include "fillit.h"

#define BUF_SIZE 21

t_square 	*create_square(int x, int y, int down, int right)
{
	t_square *new;

	new = malloc(sizeof(t_square));
	if (!new)
		return (NULL);
	new->x_coord = x;
	new->y_coord = y;
	new->down = down;
	new->right = right;
	return (new);
}

t_tetramin 	*crea_te(char l, t_square *a, t_square *b, t_square *c, t_square *d)
{
	t_tetramin *new;

	new = malloc(sizeof(t_tetramin));
	if (!new)
		return (NULL);
	new->letter = l;
	new->first = a;
	new->second = b;
	new->third = c;
	new->fourth = d;
	return (new);
}

int			is_in_tetramin(char *str, int pos, char c)
{
	int i;

	if (str[pos - 1] == c || str[pos + 1] == c || str[pos - 5] == c ||
		str[pos + 5] == c)
		return (1);
	return (0);
}

char 		*reading(char *str)
{
	int		fd;
	int		ret;
	char	*buf;
	int		i;
	//char *result;

	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!buf)
		return (NULL);
	//result = (char*)malloc(sizeof(char) * (546));
	//if (!result)
	//	return (NULL);
	if (str)
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open error");
			return (1);
		}
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			i = 0;
			while (buf[i])
				if (buf[i] == )

		}

	}


}
