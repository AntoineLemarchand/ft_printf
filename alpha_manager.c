/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:13:46 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 12:38:24 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_manage_str(format, args)
{
	char	*arg;
	int		ret;

	arg = va_arg(args, char *);
	if (!format.minus && format.minwidth > ft_strlen(arg))
	{
		while (format.minwidth > ft_strlen(arg))
			ret += write(1, &' ', 1);
	}
	ret += write(1, args, ft_strlen(arg));
	if (format.minus && format.minwidth > ft_strlen(arg))
	{
		while (format.minwidth > ft_strlen(arg))
			ret += write(1, &' ', 1);
	}
	return (ret);
}

int	ft_manage_char(format, arg)
{
	char	*arg;
	int		ret;

	arg = va_arg(args, char);
	if (!format.minus && format.minwidth > ft_strlen(arg))
	{
		while (format.minwidth > ft_strlen(arg))
			ret += write(1, &' ', 1);
	}
	ret += write(1, arg, 1);
	if (format.minus && format.minwidth > ft_strlen(arg))
	{
		while (format.minwidth > ft_strlen(arg))
			ret += write(1, &' ', 1);
	}
	return (ret);
}
