/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:58:32 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 08:16:49 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_error(int i, char **file, int j)
{
	if (j == 1)
	{
		printf("Error\nTexture or direction missing\n");
		exit(1);
	}
	if (file[i][0] == '\0')
	{
		printf("Error\nTexture or direction missing\n");
		exit(1);
	}
}

void	check_north(char **file, t_texture_coords *texture_coords)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		print_error(i, file, 0);
		if (file[i][1] != '\0' && file[i][0] == 'N' && file[i][1] == 'O')
		{
			texture_coords->no.i = i;
			return ;
		}
		while (file[i][++j] && ft_isspace(file[i][j]) == 1)
		{
			if (file[i][j + 1] != '\0' && file[i][j + 2] != '\0'
				&& file[i][j + 1] == 'N' && file[i][j + 2] == 'O')
			{
				texture_coords->no.i = i;
				texture_coords->no.j = j + 1;
				return ;
			}
		}
	}
	print_error(i, file, 1);
}

void	check_south(char **file, t_texture_coords *texture_coords)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		print_error(i, file, 0);
		if (file[i][1] != '\0' && file[i][0] == 'S' && file[i][1] == 'O')
		{
			texture_coords->so.i = i;
			return ;
		}
		while (file[i][++j] && ft_isspace(file[i][j]) == 1)
		{
			if (file[i][j + 1] != '\0' && file[i][j + 2] != '\0'
			&& file[i][j + 1] == 'S' && file[i][j + 2] == 'O')
			{
				texture_coords->so.i = i;
				texture_coords->so.j = j + 1;
				return ;
			}
		}
	}
	print_error(i, file, 1);
}

void	check_east(char **file, t_texture_coords *texture_coords)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		print_error(i, file, 0);
		if (file[i][1] != '\0' && file[i][0] == 'E' && file[i][1] == 'A')
		{
			texture_coords->ea.i = i;
			return ;
		}
		while (file[i][++j] && ft_isspace(file[i][j]) == 1)
		{
			if (file[i][j + 1] != '\0' && file[i][j + 2] != '\0'
				&& file[i][j + 1] == 'E' && file[i][j + 2] == 'A')
			{
				texture_coords->ea.i = i;
				texture_coords->ea.j = j + 1;
				return ;
			}
		}
	}
	print_error(i, file, 1);
}

void	check_west(char **file, t_texture_coords *texture_coords)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		print_error(i, file, 0);
		if (file[i][1] != '\0' && file[i][0] == 'W' && file[i][1] == 'E')
		{
			texture_coords->we.i = i;
			return ;
		}
		while (file[i][++j] && ft_isspace(file[i][j]) == 1)
		{
			if (file[i][j + 1] != '\0' && file[i][j + 2] != '\0'
				&& file[i][j + 1] == 'W' && file[i][j + 2] == 'E')
			{
				texture_coords->we.i = i;
				texture_coords->we.j = j + 1;
				return ;
			}
		}
	}
	print_error(i, file, 1);
}
