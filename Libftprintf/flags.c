/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:49:28 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/23 09:10:27 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_handler(const char *fmt, size_t *i, t_printf *pf)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '-')
			pf->ladjust = true;
		else if (fmt[*i] == '+')
			pf->plus_sign = '+';
		else if (fmt[*i] == '#')
			pf->altfmt = true;
		else if (fmt[*i] == '0')
			pf->padc = '0';
		else if (fmt[*i] == ' ')
		{
			if (pf->plus_sign == 0)
				pf->plus_sign = ' ';
		}
		else
			return (0);
		(*i)++;
	}
	return (-1);
}

int	width_handler(const char *fmt, size_t *i, t_printf *pf)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '*')
		{
			pf->width_arg = true;
			(*i)++;
			return (0);
		}
		else
		{
			while (fmt[*i] && ft_isdigit(fmt[*i]))
			{
				pf->length = 10 * pf->length + (fmt[*i] - '0');
				(*i)++;
			}
			return (0);
		}
	}
	return (-1);
}

int	precision_handler(const char *fmt, size_t *i, t_printf *pf)
{
	while (fmt[*i])
	{
		if (fmt[*i] == '*')
		{
			pf->prec_arg = true;
			(*i)++;
			return (0);
		}
		else
		{
			if (ft_isdigit(fmt[*i]))
			{
				pf->prec = 0;
				while (fmt[*i] && ft_isdigit(fmt[*i]))
				{
					pf->prec = 10 * pf->prec + (fmt[*i] - '0');
					(*i)++;
				}
				return (0);
			}
		}
		(*i)++;
	}
	return (-1);
}

int	specifier_handler(const char *fmt, size_t *i, t_printf *pf, va_list va_list)
{
	if (fmt[*i] == 'c')
		print_char(va_arg(va_list, int), pf);
	else if (fmt[*i] == 's')
		print_string(va_arg(va_list, char *), pf);
	else if (fmt[*i] == 'u')
		print_unsigned(va_arg(va_list, unsigned int), 10, pf);
	else if (fmt[*i] == 'p' || fmt[*i] == 'x' || fmt[*i] == 'X')
	{
		if (fmt[*i] == 'p' || pf->altfmt)
			pf->prefix = "0x";
		if (fmt[*i] == 'X')
			pf->capitals = 16;
		if (fmt[*i] == 'p')
			pf->truncate = 0;
		print_unsigned(va_arg(va_list, unsigned long), 16, pf);
	}
	else if (fmt[*i] == 'i' || fmt[*i] == 'd')
		print_signed(va_arg(va_list, long), 10, pf);
	else if (fmt[*i] == '%')
		ft_putchar_fd_count('%', 1, pf);
	else
		return (-1);
	(*i)++;
	return (0);
}
