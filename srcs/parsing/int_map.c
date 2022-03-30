/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:06:04 by nferre            #+#    #+#             */
/*   Updated: 2022/03/30 10:39:07 by nferre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_size_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	size = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			size++;
		if (i == 0)
			data->x = j;
	}
	data->y = i;
	return (data->y * data->x);
}

void	int_map(t_data *data, int *k, int i, int j)
{		
	if (data->map[i][j] == 'N')
		data->player_direction = 'N';
	if (data->map[i][j] == 'S')
		data->player_direction = 'S';
	if (data->map[i][j] == 'E')
		data->player_direction = 'E';
	if (data->map[i][j] == 'W')
		data->player_direction = 'W';
	*k += 1;
	data->int_map[*k] = 2;
}

void	get_int_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	i = -1;
	data->int_map = malloc(get_size_map(data->map, data) * sizeof(int));
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
				int_map(data, &k, i, j);
			else if (ft_isdigit(data->map[i][j]) == 0)
				data->int_map[++k] = -1;
			else
				data->int_map[++k] = data->map[i][j] - 48;
		}
	}
	while (++k != (data->x) * (data->y))
		data->int_map[k] = -1;
}
