/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:09:05 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/07 11:11:40 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

static int	ft_managearg(char *str, va_list args, int index)
{
	int		size;
	char	*s;
	char	c;

	size = 0;
	if (str[index] == 'c')
	{
		c = va_arg(args, int);
		size += write(1, &c, 1);
	}
	else if (str[index] == 's')
	{
		s = va_arg(args, char *);
		size += write(1, s, ft_strlen(s));
	}
	else if (str[index] == 'p')
		size += ft_putaddr(va_arg(args, unsigned long));
	else if (str[index] == 'd' || str[index] == 'i')
		size += ft_putint(va_arg(args, int));
	else if (str[index] == 'u')
		size += ft_putuint(va_arg(args, unsigned int));
	else if (str[index] == 'x')
		size += ft_puthex(va_arg(args, unsigned int), 0);
	else if (str[index] == 'X')
		size += ft_puthex(va_arg(args, unsigned int), 1);
	else if (str[index] == '%')
		size += write(1, "%", 1);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			size;
	int			i;

	size = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			size = ft_managearg((char *)str, args, ++i);
		else
		{
			write(1, &str[i], 1);
			size += 1;
		}
		i++;
	}
	va_end(args);
	return (size);
}
