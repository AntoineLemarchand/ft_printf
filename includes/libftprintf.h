/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarch <alemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:08:36 by alemarch          #+#    #+#             */
/*   Updated: 2021/12/06 17:01:42 by alemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include<unistd.h>
# include<stddef.h>
# include<stdlib.h>
# include<stdarg.h>
# include"libft.a"

typedef struct s_format {
	int		plus;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	size_t	minwidth;
}	t_format;
#endif
