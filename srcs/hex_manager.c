/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:35:37 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/07 12:30:00 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_putlhex(unsigned long nb)
{
	char	*base;
	int		size;

	size = 0;
	base = "0123456789abcdef";
	if (nb > 15)
		size += ft_putlhex(nb / 16);
	size += write(1, &base[nb % 16], 1);
	return (size);
}

int	ft_putaddr(unsigned long ptr)
{
	int	size;

	size = 0;
	size += write(1, "0x", 2);
	size += ft_putlhex(ptr);
	return (size);
}

int	ft_puthex(unsigned int nb, int big)
{
	char	*base;
	int		size;

	size = 0;
	if (big)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb > 15)
		size += ft_puthex(nb / 16, big);
	size += write(1, &base[nb % 16], 1);
	return (size);
}
