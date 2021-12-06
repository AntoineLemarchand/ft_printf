/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:09:05 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 12:30:42 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

static int	ft_isconv(char c)
{
	return (c == 'c'
		|| c == 's'
		|| c == 'p'
		|| c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == '%');
}

static t_format	ft_init_format(int reload)
{
	t_format	format;

	format.plus = 0;
	format.minus = 0;
	format.dot = 0;
	format.hash = 0;
	format.space = 0;
	format.minwidth = 0;
	if (reload)
		format.size = 0;
	return (format);
}

static int	ft_load_format(char *str, t_format format, int index)
{
	while (!ft_iconv(str[index]))
	{
		if (str[index] == '+')
			format.plus = 1;
		else if (str[index] == '-')
			format.minus = 1;
		else if (str[index] == '.')
			format.dot = 1;
		else if (str[index] == '#')
			format.hash = 1;
		else if (str[index] == ' ')
			format.space = 1;
		else if (ft_isdigit(str[index]))
			format.minwidth = ft_atoi(str[index]);
		index += 1;
	}
	return (index);
}

static int	ft_managearg(char *str, va_list args, int index)
{
	t_format	format;
	int			size;

	format = ft_init_format(0);
	index = ft_load_format(str, format, index);
	if (str[index] == 'c')
		size += ft_manage_char(format, args);
	else if (str[index] == 's')
		size += ft_manage_str(format, args);
	else if (str[index] == 'p')
		size += ft_manage_addr(format, args);
	else if (str[index] == 'd' || str[index] == 'i')
		size += ft_manage_nbr(format, args);
	else if (str[index] == 'u')
		size += ft_manage_unsigned(format, args);
	else if (str[index] == 'x')
		size += ft_manage_hex(format, args, 0);
	else if (str[index] == 'X')
		size += ft_manage_hex(format, args, 1);
	else if (str[index] == '%')
		size += write(1, '%' 1);
	index++;
	return (index);
}

int	ft_printf(const char *str, ...)
{
	t_format	print;
	va_list		args;
	int			i;
	int			size;

	size = 0;
	print = ft_init_struct(1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			i = ft_managearg(str, args, i + 1);
		else
		{
			write(1, str[i++], 1);
			size += 1;
		}
	}
	va_end(args);
	return (print.size);
}
