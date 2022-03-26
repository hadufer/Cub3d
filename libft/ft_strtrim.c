/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 20:07:22 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/04 18:00:48 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*ret;

	ret = 0;
	if (!s1 || !set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > begin)
		end--;
	ret = malloc(sizeof(char) * (end - begin + 1));
	if (ret)
		ft_strlcpy(ret, (char *)(s1 + begin), end - begin + 1);
	return (ret);
}
