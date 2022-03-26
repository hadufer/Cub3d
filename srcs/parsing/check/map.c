/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:24:27 by nferre            #+#    #+#             */
/*   Updated: 2022/03/17 08:22:59 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_character_existance(t_data *data, char c)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == c)
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
	check_character_existance(data, '0');
	check_directions(data);
}
