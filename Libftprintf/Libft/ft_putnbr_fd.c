/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:16:14 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/04 19:28:31 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		c = (n % 10) + 48;
		ft_putnbr_fd((n / 10), fd);
		write(fd, &c, 1);
	}
	else if (n < 10)
	{
		c = (n % 10) + 48;
		write(fd, &c, 1);
	}
}
