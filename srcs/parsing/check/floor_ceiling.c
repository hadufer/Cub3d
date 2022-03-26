/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 08:19:51 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 08:20:28 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_floor(char **file, t_texture_coords *texture_coords)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		print_error(i, file, 0);
		if (file[i][0] == 'F')
		{
			texture_coords->f.i = i;
			texture_coords->f.j = 0;
			return ;
		}
		while (file[i][++j] && ft_isspace(file[i][j]) == 1)
		{
			if (file[i][j + 1] == 'F')
			{
				texture_coords->f.i = i;
				texture_coords->f.j = j + 1;
				return ;
			}
		}
	}
	print_error(i, file, 1);
}

void	check_ceiling(char **file, t_texture_coords *texture_coords)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i])
	{
		j = -1;
		print_error(i, file, 0);
		if (file[i][0] == 'C')
		{
			texture_coords->c.i = i;
			texture_coords->c.j = 0;
			return ;
		}
		while (file[i][++j] && ft_isspace(file[i][j]) == 1)
		{
			if (file[i][j + 1] == 'C')
			{
				texture_coords->c.i = i;
				texture_coords->c.j = j + 1;
				return ;
			}
		}
	}
	print_error(i, file, 1);
}
