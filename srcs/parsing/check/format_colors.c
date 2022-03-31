/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:17:52 by nferre            #+#    #+#             */
/*   Updated: 2022/03/31 15:24:30 by hadufer          ###   ########.fr       */
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

void	check_format_colors(t_data *data, t_texture_coords t_c)
{
	char	*line;

	line = get_path(data->file, t_c.c, 1);
	check_line(line);
	free(line);
}
