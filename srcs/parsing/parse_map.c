/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:54:52 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 07:56:59 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_number_column(char *file, int first_c)
{
	int	nb_column;

	nb_column = 0;
	while (file[first_c])
	{
		if (file[first_c] == '\n')
			nb_column++;
		first_c++;
	}
	if (file[first_c] == '\0')
		nb_column++;
	return (nb_column);
}

int	get_max_line_length(char *file, int first_c, int last_c)
{
	int	max_line_length;
	int	line_length;

	line_length = 0;
	max_line_length = 0;
	while (first_c != last_c)
	{
		if (file[first_c] == '\n')
		{
			if (line_length > max_line_length)
				max_line_length = line_length;
			line_length = -1;
		}
		first_c++;
		line_length++;
	}
	return (max_line_length);
}

void	fill_map(char *file, char **map, int first_c, int last_c)
{
	int	i;
	int	j;
	int	max_length;

	max_length = get_max_line_length(file, first_c, last_c);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (++j != max_length)
		{
			if (file[first_c] != '\n' && file[first_c] != ' ')
				map[i][j] = file[first_c];
			else
				map[i][j] = ' ';
			if (file[first_c] != '\n' && file[first_c])
				first_c++;
		}
		if (file[first_c] == '\n' && file[first_c] != '\0')
			first_c++;
	}
}

char	**get_map(char *file, int first_c, int last_c)
{
	int		i;
	char	**map;
	int		max_column;
	int		max_length;

	max_length = get_max_line_length(file, first_c, last_c);
	max_column = get_number_column(file, first_c);
	i = -1;
	map = malloc(sizeof(char *) * (max_column + 1));
	while (++i != max_column)
	{
		map[i] = malloc(sizeof(char) * (max_length) + 1);
		ft_memset(map[i], 2, max_length);
		map[i][max_length] = '\0';
	}
	map[max_column] = NULL;
	fill_map(file, map, first_c, last_c);
	return (map);
}

char	**parse_map(char *file, int i)
{
	char	**map;
	int		first_c;
	int		last_c;

	first_c = get_first_character_in_map(file, i);
	last_c = get_last_character_in_map(file, first_c);
	map = get_map(file, first_c, last_c);
	return (map);
}
