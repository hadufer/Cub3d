/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:22:09 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/18 11:26:35 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_itoa_util(long *nb, int *neg, int *tmp)
{
	if ((*nb) < 0)
	{
		(*nb) = -(*nb);
		(*neg) = -1;
		(*tmp)++;
	}
	while ((*nb))
	{
		(*nb) /= 10;
		(*tmp)++;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	long	nb;
	int		neg;
	int		tmp;

	nb = (long)n;
	neg = 1;
	tmp = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	ft_itoa_util(&nb, &neg, &tmp);
	nb = (long)n * neg;
	ret = malloc(sizeof(char) * tmp + 1);
	if (!ret)
		return (NULL);
	ret[tmp] = 0;
	while ((tmp - 1) >= 0)
	{
		ret[tmp - 1] = (nb % 10) + 48;
		nb /= 10;
		tmp--;
	}
	if (neg == -1)
		ret[0] = '-';
	return (ret);
}
