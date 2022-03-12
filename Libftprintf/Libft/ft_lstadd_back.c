/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:58:36 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/05 12:06:26 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **last, t_list *new)
{
	t_list	*tmp;

	tmp = *last;
	if (!*last)
	{
		*last = new;
		return ;
	}
	if (!new)
		return ;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
