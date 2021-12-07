/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:31:03 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/07 12:52:40 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(int c)
{
	int	size;

	size = 0;
	size += write(1, &c, 1);
	return (size);
}

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
		size += write(1, s++, 1);
	return (size);
}
