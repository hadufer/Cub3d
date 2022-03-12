/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:34:37 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/04 20:28:41 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **last, t_list *new)
{
	if (!last)
	{
		*last = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *last;
	*last = new;
}
