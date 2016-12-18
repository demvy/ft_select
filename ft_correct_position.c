
#include "fillit.h"

int	ft_correct_position(int pos, char *str, int size)
{
	int	n;
	int	max;

	n = 0;
	max = (int)ft_strlen(str) - 2;
	if (pos != 0 && str[pos - 1] == '.')
	{
		n += 1;
		if (pos - 2 >= 0 && str[pos - 2] == '.')
		{
			n += 1;
			if (pos - 3 >= 0 && str[pos - 3] == '.')
				n += 1;
			if (pos - size - 3 >= 0 && str[pos - size - 3] == '.')
				n += 1;
			if (pos + size - 1 <= max && str[pos + size - 1] == '.')
				n += 1;
		}
		if (pos - size - 2 >= 0 && str[pos - size - 2] == '.')
			n += 1;
		if (n < 3)
			return (0);
	}
	return (1);
}

/*int	ft_is_good_place(int pos, char *str, int size, int mode)
{
	int	n;
	int	max;

	if (mode == 0)
		return (1);
	n = 0;
	max = (int)ft_strlen(str) - 2;
	if (pos != 0 && str[pos - 1] == '.')
	{
		n += 1;
		if (pos - 2 >= 0 && str[pos - 2] == '.')
			n += 1;
		if (pos - 3 >= 0 && str[pos - 3] == '.')
			n += 1;
		if (pos - 4 >= 0 && str[pos - 4] == '.')
			n += 1;
		if (pos - (size + 1) - 1 >= 0 && str[pos - (size + 1) - 1] == '.')
			n += 1;
		if (pos - (size + 1) >= 0 && str[pos - (size + 1)] == '.')
			n += 1;
		if (pos - (size + 1) + 1 >= 0 && str[pos - (size + 1) + 1] == '.')
			n += 1;
		if (pos - (size + 1) - 2 >= 0 && str[pos - (size + 1) - 2] == '.')
			n += 1;
		if (pos - (size + 1) - 3 >= 0 && str[pos - (size + 1) - 3] == '.')
			n += 1;
		if (pos - (size + 1) * 2 - 1 >= 0 && str[pos - (size + 1) * 2 - 1] == '.')
			n += 1;
		if (pos - (size + 1) * 2 >= 0 && str[pos - (size + 1) * 2] == '.')
			n += 1;
		if (pos - (size + 1) * 2 - 2 >= 0 && str[pos - (size + 1) * 2 - 2] == '.')
			n += 1;
		if (pos - (size + 1) * 3 - 1 >= 0 && str[pos - (size + 1) * 3 - 1] == '.')
			n += 1;
		if (pos + size < max && str[pos + size] == '.')
			n += 1;
		if (pos + size + 1 < max && str[pos + size + 1] == '.')
			n += 1;
		if (pos + size + 2 < max && str[pos + size + 2] == '.')
			n += 1;
		if (pos + (size + 1) * 2 - 1 < max && str[pos + (size + 1) * 2 - 1] == '.')
			n += 1;
		if (pos + (size + 1) * 2 < max && str[pos + (size + 1) * 2] == '.')
			n += 1;
		if (pos + (size + 1) * 3 - 1 < max && str[pos + (size + 1) * 3 - 1] == '.')
			n += 1;
		if (pos + size - 1 < max && str[pos + size - 1] == '.')
			n += 1;
		if (pos + size - 2 < max && str[pos + size - 2] == '.')
			n += 1;
		if (pos + (size + 1) * 2 - 2 < max && str[pos + (size + 1) * 2 - 2] == '.')
			n += 1;
		if (n < 4)
			return (0);
	}
	return (1);
}*/

static int	ft_check_back_dots()
{
	int i;
	int	dots;

	i = 0;
	dots = 0;
	while (++i <= deep)
	{
		if (pos - i >= 0)
		{
			if (str[pos - i] == '.')
				dots += 1;
			else
				return (dots);
		}
		else
			return (dots);
	}
	return (dots);
}

int			ft_check_back_up(char *str, int i, int size);
{
	int n;

	n = 0;
	n += ft_check_back_dots(i, str, 3);
	if (i - size - 1 >= 0 && str[i - size - 1] == '.')
	{
		n = n + 1 +  ft_check_back_dots(i - size - 1, str, 2);
		if (i - 2 * size - 2 >= 0 && str[i - 2 * size - 2] == '.')
		{
			n = n + 1 + ft_check_back_dots(i - 2 * size - 2, str, 1);
			if (i - 3 * size - 3 >= 0 && str[i - 3 * size - 3] == '.')
				n += 1;
		}
		else if (i - 2 * size - 3 >= 0 && str[i - 2 * size - 3] == '.')
			n += 1;
	}
	else if (n >= 1 && i - size - 2 >= 0 && str[i - size - 2] == '.')
		n = n + 1 +  ft_check_back_dots(i - size - 2, str, 1);
	else if (n >= 2 && i - size - 3 >= 0 && str[i - size - 3] == '.')
		n += 1;
	return (n);
}

int			ft_check_back_down(char *str, int i, int size);
{
	int n;
	int	p;
	int max;

	n = 0;
	p = 0;
	max = (int)ft_strlen(str) - 2;
	p += ft_check_back_dots(i, str, 3);
	if (i + size + 1 <= max && str[i + size + 1] == '.')
	{
		n = n + 1 +  ft_check_back_dots(i + size + 1, str, 2);
		if (i + 2 * size + 2 <= max && str[i + 2 * size + 2] == '.')
		{
			n = n + 1 + ft_check_back_dots(i + 2 * size + 2, str, 1);
			if (i + 3 * size + 3 <= max && str[i + 3 * size + 3] == '.')
				n += 1;
		}
		else if (i + 2 * size + 3 <= max && str[i + 2 * size + 3] == '.')
			n += 1;
	}
	else if (p >= 1 && i + size + 2 <= max && str[i + size + 2] == '.')
		n = n + 1 +  ft_check_back_dots(i + size + 2, str, 1);
	else if (p >= 2 && i + size + 3 <= max && str[i + size + 3] == '.')
		n += 1;
	return (n);
}
