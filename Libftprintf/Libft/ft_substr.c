/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:18:09 by hadufer           #+#    #+#             */
/*   Updated: 2021/11/02 11:09:34 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ret = malloc(0);
		*ret = '\0';
		return (ret);
	}
	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!ret)
		return (NULL);
	while (s[i] && (i < len))
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
