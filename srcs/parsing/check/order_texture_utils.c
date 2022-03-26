/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_texture_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:23:54 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 08:24:13 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_size(char *path)
{
	char	buf[2];
	int		fd;
	int		size;
	int		r;

	size = 0;
	buf[1] = '\0';
	r = 1;
	fd = open(path, O_RDONLY);
	while (r == 1)
	{
		r = read(fd, buf, 1);
		if (r == 1)
			size++;
	}
	close(fd);
	return (size);
}

char	*get_file(char *path)
{
	char	*file;
	int		r;
	int		i;
	int		fd;
	char	buf[2];	

	r = 1;
	i = 0;
	buf[1] = '\0';
	file = malloc(sizeof(char) * (get_size(path) + 1));
	fd = open(path, O_RDONLY);
	while (r == 1)
	{
		r = read(fd, buf, 1);
		if (r == 1)
			file[i++] = buf[0];
	}
	file[get_size(path)] = '\0';
	return (file);
}
