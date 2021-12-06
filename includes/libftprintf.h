/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:08:36 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 22:53:51 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include<unistd.h>
# include<stddef.h>
# include<stdlib.h>
# include<stdarg.h>
# include"libft.h"

typedef struct s_format {
	int		plus;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	size_t	minwidth;
	size_t	size;
}	t_format;
int	ft_manage_char(t_format *format, va_list args);
int	ft_manage_str(t_format *format, va_list args);
int	ft_manage_nbr(t_format *format, va_list args);
int	ft_manage_unsigned(t_format *format, va_list args);
int	ft_manage_hex(t_format *format, va_list args, int big);
int	ft_manage_addr(t_format *format, va_list args);
int	ft_printf(const char *str, ...);
#endif
