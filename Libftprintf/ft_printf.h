/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:38:34 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/23 09:12:35 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_printf
{
	int		altfmt;
	int		ladjust;
	int		plus_sign;
	int		padc;
	int		prec;
	int		capitals;
	int		length;
	int		width_arg;
	int		prec_arg;
	int		last_percent;
	int		return_value;
	int		truncate;
	char	*prefix;
}			t_printf;
int			ft_printf(const char *fmt, ...);
void		print_signed(long nb, int base, t_printf *pf);
void		print_unsigned(unsigned long nb, int base, t_printf *pf);
void		print_char(int c, t_printf *pf);
void		print_string(char *str, t_printf *pf);
int			flag_handler(const char *fmt, size_t *i, t_printf *pf);
int			width_handler(const char *fmt, size_t *i, t_printf *pf);
int			precision_handler(const char *fmt, size_t *i, t_printf *pf);
int			specifier_handler(const char *fmt, size_t *i, \
								t_printf *pf, va_list va_list);
void		ft_putchar_fd_count(char c, int fd, t_printf *pf);
void		ft_putstr_fd_count(char *str, int fd, t_printf *pf);
#endif
