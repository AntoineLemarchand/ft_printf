/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:45:33 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/07 11:29:59 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_putint(int nb)
{
	unsigned int	n;
	char			c;
	int				size;

	size = 0;
	if (nb < 0)
	{
		n = -nb;
		size += write(1, "-", 1);
	}
	else
		n = nb;
	if (n > 10)
		ft_putint(n / 10);
	c = n % 10 + 48;
	size += write(1, &c, 1);
	return (size);
}

int	ft_putuint(unsigned int nb)
{
	int		size;
	char	c;

	size = 0;
	if (nb > 10)
		ft_putint(nb / 10);
	c = nb % 10 + 48;
	size += write(1, &c, 1);
	return (size);
}
