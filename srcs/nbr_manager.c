/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:45:33 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 22:37:46 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

static size_t	ft_intlen(int nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static size_t	ft_uintlen(unsigned int nb)
{
	size_t	size;

	size = 0;
	while (nb)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

static int	ft_manage_nbrspace(size_t width, int zero, int nb)
{
	int	ret;

	ret = 0;
	while (width > ft_intlen(nb))
	{
		if (zero)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
		width--;
	}
	return (ret);
}

int	ft_manage_nbr(t_format *format, va_list args)
{
	int		arg;
	int		ret;

	arg = va_arg(args, int);
	ret = 0;
	if (!format->minus && format->minwidth > ft_intlen(arg))
		ft_manage_nbrspace(format->minwidth, format->zero, arg);
	// ici imprimer et compter les chiffres
	if (format->minus && format->minwidth > ft_intlen(arg))
		ft_manage_nbrspace(format->minwidth, format->zero, arg);
	return (ret);
}

int	ft_manage_unsigned(t_format *format, va_list args)
{
	int				ret;
	unsigned int	arg;

	arg = va_arg(args, unsigned int);
	ret = 0;
	if (!format->minus && format->minwidth > ft_uintlen(arg))
		ft_manage_nbrspace(format->minwidth, format->zero, arg);
	// ici imprimer et compter les chiffres
	if (format->minus && format->minwidth > ft_uintlen(arg))
		ft_manage_nbrspace(format->minwidth, format->zero, arg);
	return (ret);
}
