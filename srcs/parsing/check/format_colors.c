/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:17:52 by nferre            #+#    #+#             */
/*   Updated: 2022/03/30 10:39:51 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_line(char *line)
{
	int	i;
	int	temp;

	temp = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ',')
			temp++;
	}
	if (temp != 2)
	{
		printf("Error\nInvalid format in colors\n");
		free(line);
		exit(1);
	}
}

void	check_format_colors(t_data *data, t_texture_coords texture_coords)
{
	char	*line;

	line = get_path(data->file, texture_coords.c, 1);
	check_line(line);
	free(line);
}
