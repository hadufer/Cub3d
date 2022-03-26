/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:06:04 by nferre            #+#    #+#             */
/*   Updated: 2022/03/25 17:43:11 by nferre           ###   ########.fr       */
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
				data->map[++k] = 0;
			else if (ft_isdigit(data->map[i][j]) == 0)
				data->int_map[++k] = -1;
			else
				data->int_map[++k] = data->map[i][j] - 48;
		}
	}
	while (++k != (data->x) * (data->y))
		data->int_map[k] = -1;
}
