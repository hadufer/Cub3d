/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:07:01 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/23 09:19:44 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar_fd_count(char c, int fd, t_printf *pf)
{
	pf->return_value++;
	write(fd, &c, 1);
}

void	ft_putstr_fd_count(char *s, int fd, t_printf *pf)
{
	if (!s)
		return ;
	pf->return_value += ft_strlen(s);
	write(fd, s, ft_strlen(s));
}

void	print_char(int c, t_printf *pf)
{
	while (!pf->ladjust && (--pf->length - 1) >= 0)
		ft_putchar_fd_count(' ', 1, pf);
	ft_putchar_fd_count(c, 1, pf);
	while (pf->ladjust && (--pf->length - 1) >= 0)
		ft_putchar_fd_count(' ', 1, pf);
}

void	print_string(char *str, t_printf *pf)
{
	if (!str)
		ft_putstr_fd_count("(null)", 1, pf);
	else
	{
		while (!pf->ladjust && (--pf->length - (int)ft_strlen(str)) >= 0)
			ft_putchar_fd_count(' ', 1, pf);
		ft_putstr_fd_count(str, 1, pf);
		while (pf->ladjust && (--pf->length - (int)ft_strlen(str)) >= 0)
			ft_putchar_fd_count(' ', 1, pf);
	}
}
