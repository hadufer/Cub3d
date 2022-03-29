/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:24:27 by nferre            #+#    #+#             */
/*   Updated: 2022/03/29 16:09:30 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_character_existance(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == 'N'
				|| data->map[i][j] == 'S' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W')
				return ;
		}
	}
	printf("Error\nInvalid map descrption\n");
	exit(1);
}

void	check_directions(t_data *data)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
				temp++;
	}
	if (temp != 1)
	{
		printf("Error\nInvalid map descrption\n");
		exit(1);
	}
}

void	check_map(t_data *data)
{
	check_character_existance(data);
	check_directions(data);
}
