/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:09:05 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/07 14:14:55 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_managearg(char c, va_list args)
{
	int		size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		size += ft_putaddr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		size += ft_putint(va_arg(args, int));
	else if (c == 'u')
		size += ft_putuint(va_arg(args, unsigned int));
	else if (c == 'x')
		size += ft_puthex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		size += ft_puthex(va_arg(args, unsigned int), 1);
	else if (c == '%')
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
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			size += ft_managearg(str[++i], args);
		else
			size += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (size);
}
