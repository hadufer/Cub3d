/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_existance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:24:26 by nferre            #+#    #+#             */
/*   Updated: 2022/03/21 08:29:58 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_yep(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i < 4 || line[i - 1] != 'p' || line[i - 2] != 'e'
		|| line[i - 3] != 'y' || line[i - 4] != '.')
	{
		printf("Error\nInvalid map extension for textures\n");
		exit(1);
	}	
}

void	check_existence(char *line)
{
	int		fd;
	char	buf[1];

	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n%s for textures\n", strerror(errno));
		exit(1);
	}
	if (read(fd, buf, 1) == -1)
	{
		printf("Error\n%s for textures\n", strerror(errno));
		exit(1);
	}
	close(fd);
}

void	check_texture_existence(t_data *data)
{
	check_yep(data->path_to_north);
	check_existence(data->path_to_north);
	check_yep(data->path_to_south);
	check_existence(data->path_to_south);
	check_yep(data->path_to_east);
	check_existence(data->path_to_east);
	check_yep(data->path_to_west);
	check_existence(data->path_to_west);
}
