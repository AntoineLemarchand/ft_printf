/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:13:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 16:59:37 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libftprintf.h"

int	ft_manage_str(t_format *format, va_list args)
{
	char	*arg;
	int		ret;

	arg = va_arg(args, char *);
	ret = 0;
	if (!format->minus && format->minwidth > ft_strlen(arg))
	{
		while (format->minwidth > ft_strlen(arg))
			ret += write(1, " ", 1);
	}
	ret += write(1, args, ft_strlen(arg));
	if (format->minus && format->minwidth > ft_strlen(arg))
	{
		while (format->minwidth > ft_strlen(arg))
			ret += write(1, " ", 1);
	}
	return (ret);
}

int	ft_manage_char(t_format *format, va_list args)
{
	char	*arg;
	int		ret;

	arg = va_arg(args, int);
	ret = 0;
	if (!format->minus && format->minwidth > (int)ft_strlen(arg))
	{
		while (format->minwidth > ft_strlen(arg))
			ret += write(1, " ", 1);
	}
	ret += write(1, arg, 1);
	if (format->minus && format->minwidth > ft_strlen(arg))
	{
		while (format->minwidth > ft_strlen(arg))
			ret += write(1, " ", 1);
	}
	return (ret);
}
