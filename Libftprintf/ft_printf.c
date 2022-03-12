/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:39:09 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/23 09:14:05 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static void	reset_pf(t_printf *pf)
{
	pf->prec = -1;
	pf->ladjust = 0;
	pf->padc = ' ';
	pf->plus_sign = 0;
	pf->altfmt = 0;
	pf->length = 0;
	pf->width_arg = 0;
	pf->prec_arg = 0;
	pf->last_percent = -1;
	pf->capitals = 0;
	pf->prefix = NULL;
	pf->truncate = 1;
}

static void	print_last_percent(const char *fmt, size_t *i, t_printf *pf)
{
	if (pf->last_percent == -1)
		return ;
	else
	{
		while ((size_t)pf->last_percent != *i)
		{
			ft_putchar_fd_count(fmt[pf->last_percent], 1, pf);
			(pf->last_percent)++;
		}
		pf->last_percent = -1;
	}
}

static int	exit_clean(int i, t_printf	*pf, va_list va_list)
{
	(void)pf;
	va_end(va_list);
	if (i == -1)
		return (-1);
	return (pf->return_value);
}

int	handler_wrapper(size_t *i, t_printf *pf, va_list va_list, const char *fmt)
{
	if (flag_handler(fmt, i, pf) == -1)
		return (-1);
	if (width_handler(fmt, i, pf) == -1)
		return (-1);
	if (fmt[*i] == '.')
	{
		(*i)++;
		if (precision_handler(fmt, i, pf) == -1)
			return (-1);
	}
	if (specifier_handler(fmt, i, pf, va_list) == -1)
		print_last_percent(fmt, i, pf);
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	t_printf	pf;
	va_list		va_list;
	size_t		i;

	pf.return_value = 0;
	va_start(va_list, fmt);
	i = 0;
	while (fmt[i])
	{
		reset_pf(&pf);
		if (fmt[i] != '%')
			ft_putchar_fd_count(fmt[i++], 1, &pf);
		else
		{
			pf.last_percent = i;
			i++;
			if (handler_wrapper(&i, &pf, va_list, fmt) == -1)
				return (exit_clean(-1, &pf, va_list));
		}
	}
	return (exit_clean(i, &pf, va_list));
}
