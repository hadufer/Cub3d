/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:07:34 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/27 10:03:49 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	mini_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] && s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == 0 && s2[i] == 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				tmp[2];

	i = 0;
	tmp[0] = 1;
	tmp[1] = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			tmp[0] *= -1;
		i++;
	}
	if (mini_strcmp((char *)(str + i), "2147483647"))
		return (INT_MAX * tmp[0]);
	else if (mini_strcmp((char *)(str + i), "-2147483648"))
		return (INT_MIN * tmp[0]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp[1] = (str[i] - 48) + (10 * tmp[1]);
		i++;
	}
	return (tmp[1] * tmp[0]);
}
