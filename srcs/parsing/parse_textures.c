/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 08:55:40 by nferre            #+#    #+#             */
/*   Updated: 2022/03/22 07:48:31 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_number_line(char *path)
{
	int		i;
	char	**file;

	file = parse_file(path);
	i = 0;
	while (file[i])
		i++;
	free_map(file);
	if (i != 2)
	{
		printf("Error\nInvalid format in texture\n");
		exit(1);
	}	
}

void	check_characters_file(char *path)
{
	int		j;
	int		i;
	char	**file;

	i = -1;
	file = parse_file(path);
	while (file[++i])
	{
		j = -1;
		while (file[i][++j])
		{
			if (file[i][j] != ',' && ft_isdigit(file[i][j]) == 0)
			{
				printf("Error\nInvalid character in texture\n");
				exit(1);
			}
		}
	}
	free_map(file);
}

void	error(char **line, char **file)
{
	free_map(line);
	free_map(file);
	printf("Error\nInvalid format in texture\n");
	exit(1);
}	

t_color	get_texture(char *path)
{
	t_color	color;
	char	**line;
	char	**file;

	file = parse_file(path);
	line = ft_split(file[0], ',');
	if (line[0] == NULL)
		error(line, file);
	color.r = ft_atoi(line[0]);
	if (line[1] == NULL)
		error(line, file);
	color.g = ft_atoi(line[1]);
	if (line[2] == NULL)
		error(line, file);
	color.b = ft_atoi(line[2]);
	free_map(line);
	free_map(file);
	if (color.r < 0 || color.r > 255 || color.b < 0 || color.b > 255
		|| color.g < 0 || color.g > 255)
	{
		printf("Error\nInvalid range on color in texture\n");
		exit(1);
	}
	return (color);
}

void	get_textures(t_data *data)
{
	check_number_line(data->path_to_north);
	check_characters_file(data->path_to_north);
	data->north_texture = get_texture(data->path_to_north);
	check_characters_file(data->path_to_south);
	data->south_texture = get_texture(data->path_to_south);
	check_characters_file(data->path_to_east);
	data->east_texture = get_texture(data->path_to_east);
	check_characters_file(data->path_to_west);
	data->west_texture = get_texture(data->path_to_west);
}
