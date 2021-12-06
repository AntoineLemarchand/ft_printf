/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:09:05 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 16:48:04 by alemarch         ###   ########.fr       */
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
	t_format	*format;

	if (reload)
		format = malloc(sizeof(t_format));
	format->plus = 0;
	format->minus = 0;
	format->dot = 0;
	format->hash = 0;
	format->space = 0;
	format->minwidth = 0;
	if (reload)
		format->size = 0;
	return (format);
}

static int	ft_load_format(char *str, t_format format, int index)
{
	while (!ft_iconv(str[index]))
	{
		if (str[index] == '+')
			format->plus = 1;
		else if (str[index] == '-')
			format->minus = 1;
		else if (str[index] == '.')
			format->dot = 1;
		else if (str[index] == '#')
			format->hash = 1;
		else if (str[index] == ' ')
			format->space = 1;
		else if (ft_isdigit(str[index]))
			format->minwidth = ft_atoi(str[index]);
		index += 1;
	}
	return (index);
}

static int	ft_managearg(char *str, va_list args, int index, t_format format)
{
	t_format	*format;

	format = ft_init_format(0);
	index = ft_load_format(str, format, index);
	if (str[index] == 'c')
		format->size += ft_manage_char(format, args);
	else if (str[index] == 's')
		format->size += ft_manage_str(format, args);
	else if (str[index] == 'p')
		format->size += ft_manage_addr(format, args);
	else if (str[index] == 'd' || str[index] == 'i')
		format->size += ft_manage_nbr(format, args);
	else if (str[index] == 'u')
		format->size += ft_manage_unsigned(format, args);
	else if (str[index] == 'x')
		format->size += ft_manage_hex(format, args, 0);
	else if (str[index] == 'X')
		format->size += ft_manage_hex(format, args, 1);
	else if (str[index] == '%')
		format->size += write(1, '%' 1);
	index++;
	return (index);
}

int	ft_printf(const char *str, ...)
{
	t_format	*format;
	va_list		args;
	int			i;
	int			size;

	size = 0;
	format = ft_init_struct(1);
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
	free(format);
	return (size);
}
