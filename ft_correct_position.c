
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
