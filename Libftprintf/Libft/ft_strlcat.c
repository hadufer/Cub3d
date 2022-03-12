/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:40:55 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/18 15:36:16 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_l;
	unsigned int	src_l;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	i = 0;
	j = 0;
	if (!size || dest_l > size)
		return (src_l + size);
	while (dest[i])
		i++;
	while (src[j] && ((i + j) < size - 1))
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (src_l + i);
}
