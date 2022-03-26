/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:11:31 by nferre            #+#    #+#             */
/*   Updated: 2022/03/22 07:31:27 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	assign_coords(t_texture_coords texture_coords, int floor,
	int *i, int *j)
{
	if (floor == 1)
	{
		*i = texture_coords.f.i;
		*j = texture_coords.f.j;
	}
	else
	{
		*i = texture_coords.c.i;
		*j = texture_coords.c.j;
	}	
}

void	check_characters_line(char **file, t_texture_coords texture_coords,
	int floor)
{
	int	i;
	int	j;

	assign_coords(texture_coords, floor, &i, &j);
	j++;
	while (ft_isspace(file[i][j]) == 1)
		j++;
	while (ft_isspace(file[i][j]) == 0)
	{
		if (ft_isdigit(file[i][j]) == 0 && file[i][j] != ',')
		{
			printf("Error\nInvalid character in color\n");
			exit(1);
		}
		j++;
	}
}

void	check_number_point(char **file, t_texture_coords texture_coords,
	int floor)
{
	int	i;
	int	j;
	int	number_point;

	number_point = 0;
	assign_coords(texture_coords, floor, &i, &j);
	j++;
	while (ft_isspace(file[i][j]) == 1)
		j++;
	while (ft_isspace(file[i][j]) == 0)
	{
		if (file[i][j] == ',')
			number_point++;
		j++;
	}
	if (number_point != 2)
	{
		printf("Error\nInvalid number of decimal points\n");
		exit(1);
	}
}

void	check_colors(char *path, t_texture_coords texture_coords)
{
	char	**file;

	file = parse_file(path);
	check_characters_line(file, texture_coords, 1);
	check_characters_line(file, texture_coords, 0);
	check_number_point(file, texture_coords, 1);
	check_number_point(file, texture_coords, 0);
	free_map(file);
}
