/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:08:36 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/07 14:16:40 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putint(int nb);
int	ft_putuint(unsigned int nb);
int	ft_puthex(unsigned int nb, int big);
int	ft_putaddr(unsigned long ptr);
int	ft_printf(const char *str, ...);
#endif
