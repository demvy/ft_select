#include "../libft/libft.h"
#include "ft_select.h"

void		ft_putspace(int len, int arg_len, int fd)
{
	while ((len-- - arg_len) > 0)
		ft_putchar_fd(' ', fd);
}

void		p(char c, va_list list, int len, int fd)
{
	int		arg_len;
	char	*tmp;
	int		arg;
	char	*arg1;

	if (c == 'd')
	{
		arg = va_arg(list, int);
		tmp = ft_itoa(arg);
		arg_len = ft_strlen(tmp);
		ft_putspace(len, arg_len, fd);
		ft_putnbr_fd(arg, fd);
		free(tmp);
	}
	else if (c == 's')
	{
		arg1 = va_arg(list, char*);
		arg_len = ft_strlen(arg1);
		ft_putspace(len, arg_len, fd);
		ft_putstr_fd(arg1, fd);
	}
}

void		p_l(char c, va_list list, int len, int fd)
{
	int		arg_len;
	char	*tmp;
	int		arg;
	char	*arg1;

	if (c == 'd')
	{
		arg = va_arg(list, int);
		tmp = ft_itoa(arg);
		arg_len = ft_strlen(tmp);
		ft_putnbr_fd(arg, fd);
		ft_putspace(len, arg_len, fd);
		free(tmp);
	}
	else if (c == 's')
	{
		arg1 = va_arg(list, char*);
		arg_len = ft_strlen(arg1);
		ft_putstr_fd(arg1, fd);
		ft_putspace(len, arg_len, fd);
	}
}

int			get_printf_le(char **str, va_list list)
{
	int		len;

	len = 1;
	if (**str == '-')
	{
		len = -1;
		(*str)++;
	}
	if (**str == '*')
	{
		len *= va_arg(list, int);
		(*str)++;
	}
	else if (**str >= 49 && **str <= 57)
		len = ft_atoi(*str);
	return (len);
}

void		ft_printf_fd(int fd, char *s, ...)
{
	va_list	args;
	int		fl;

	va_start(args, s);
	while (*s != '\0')
	{
		while (*s != '\0' && *s != '%')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		if (*s != '\0')
		{
			s++;
			fl = get_printf_le(&s, args);
			while (*s != '\0' && *s >= 48 && *s <= 57)
				s++;
		}
		if (*s != '\0' && (*s == 'd' || *s == 's'))
			(fl > 0) ? p(*s, args, fl, fd) : p_l(*s, args, -1 * fl, fd);
		if (*s != '\0')
			s++;
		fl = 0;
	}
	va_end(args);
}