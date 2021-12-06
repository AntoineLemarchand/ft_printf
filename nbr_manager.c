/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:45:33 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 12:49:42 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (nb < 0)
		size++;
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
	while (width > ft_nbrlen(nb))
	{
		if (zero)
			ret += write(1, '0', 1);
		else
			ret += write(1, ' ', 1);
		width--;
	}
	return (ret);
}

int	ft_manage_nbr(format, args)
{
	char	*arg;
	int		ret;

	arg = va_arg(args, int);
	if (!format.minus && format.minwidth > ft_intlen(arg))
		ft_manage_nbrspace(format.minwidth, format.zero, arg);
	ret += write(1, args, ft_nbrlen(arg));
	if (format.minus && format.minwidth > ft_intlen(arg))
		ft_manage_nbrspace(format.minwidth, format.zero, arg);
	return (ret);
}

int	ft_manage_unsigned(format, args)
{
	unsigned int	ret;
	char			*arg;

	arg = va_arg(args, unsigned int);
	if (!format.minus && format.minwidth > ft_uintlen(arg))
		ft_manage_nbrspace(format.minwidth, format.zero, arg);
	ret += write(1, args, ft_nbrlen(arg));
	if (format.minus && format.minwidth > ft_uintlen(arg))
		ft_manage_nbrspace(format.minwidth, format.zero, arg);
	return (ret);
}
