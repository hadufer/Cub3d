/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parse.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: nferre <nferre@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/03/15 12:51:27 by nferre			#+#	#+#			 */
/*   Updated: 2022/03/17 07:45:01 by nferre		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "parsing.h"

char	*get_path(char **file, t_coords coords, int i)
{
	int		size;
	char	*line;
	int		j;

	size = 0;
	coords.j += i;
	while (ft_isspace(file[coords.i][coords.j]) == 1)
		coords.j++;
	j = coords.j;
	while (file[coords.i][coords.j]
		&& ft_isspace(file[coords.i][coords.j++]) == 0)
		size++;
	line = ft_strndup(&file[coords.i][j], size);
	return (line);
}

void	get_paths(t_data *data, t_texture_coords texture_coords)
{
	data->path_to_north = get_path(data->file, texture_coords.no, 2);
	data->path_to_south = get_path(data->file, texture_coords.so, 2);
	data->path_to_east = get_path(data->file, texture_coords.ea, 2);
	data->path_to_west = get_path(data->file, texture_coords.we, 2);
}

int	get_color(char *line, int offset)
{
	char	*temp;
	int		i;
	int		color;

	i = 0;
	while (offset-- != 0)
	{
		while (*line != ',')
			line++;
		if (*line == ',')
			line++;
	}
	while (line[i] != ',' && line[i])
		i++;
	offset--;
	temp = ft_strndup(line, i);
	temp[i] = '\0';
	if (ft_atoi(temp) > 255 || ft_atoi(temp) < 0)
	{
		printf("Error\nInvalid range on colors\n");
		exit (1);
	}
	free(temp);
	color = ft_atoi(temp);
	return (color);
}

void	get_colors(t_data *data, t_texture_coords texture_coords)
{
	char	*line;

	line = get_path(data->file, texture_coords.c, 1);
	data->ceiling_color.r = get_color(line, 0);
	data->ceiling_color.g = get_color(line, 1);
	data->ceiling_color.b = get_color(line, 2);
	free(line);
	line = get_path(data->file, texture_coords.f, 1);
	data->floor_color.r = get_color(line, 0);
	data->floor_color.g = get_color(line, 1);
	data->floor_color.b = get_color(line, 2);
	free(line);
}

t_data	*parse(int argc, char **argv)
{
	t_texture_coords	texture_coords;
	t_data				*data;

	data = malloc(sizeof(t_data));
	texture_coords = checker(argv[1], data, argc);
	get_paths(data, texture_coords);
	// get_textures(data);
	check_texture_existence(data);
	// get_colors(data, texture_coords);
	get_int_map(data);
	return (data);
}
