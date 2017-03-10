/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdemeshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:50:27 by vdemeshk          #+#    #+#             */
/*   Updated: 2017/01/29 16:50:31 by vdemeshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putspaces(int len, int arg_len)
{
	while ((len-- - arg_len) > 0)
		ft_putchar(' ');
}

void		pr(char c, va_list list, int len)
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
		ft_putspaces(len, arg_len);
		ft_putnbr(arg);
		free(tmp);
	}
	else if (c == 's')
	{
		arg1 = va_arg(list, char*);
		arg_len = ft_strlen(arg1);
		ft_putspaces(len, arg_len);
		ft_putstr(arg1);
	}
}

void		pr_l(char c, va_list list, int len)
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
		ft_putnbr(arg);
		ft_putspaces(len, arg_len);
		free(tmp);
	}
	else if (c == 's')
	{
		arg1 = va_arg(list, char*);
		arg_len = ft_strlen(arg1);
		ft_putstr(arg1);
		ft_putspaces(len, arg_len);
	}
}

int			get_printf_len(char **str, va_list list)
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

void		ft_printf(char *str, ...)
{
	va_list	args;
	int		f_len;

	va_start(args, str);
	while (*str != '\0')
	{
		while (*str != '\0' && *str != '%')
		{
			ft_putchar(*str);
			str++;
		}
		if (*str != '\0')
		{
			str++;
			f_len = get_printf_len(&str, args);
			while (*str != '\0' && *str >= 48 && *str <= 57)
				str++;
		}
		if (*str != '\0' && (*str == 'd' || *str == 's'))
			(f_len > 0) ? pr(*str, args, f_len) : pr_l(*str, args, -1 * f_len);
		if (*str != '\0')
			str++;
		f_len = 0;
	}
	va_end(args);
}
