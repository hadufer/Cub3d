/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:18:06 by nferre            #+#    #+#             */
/*   Updated: 2022/03/31 15:48:20 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	check_texture_map(t_data *data, char x, char y)
{	
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = -1;
	while (data->file[++i])
	{
		j = -1;
		while (data->file[i][++j])
		{
			if (data->file[i][j] == x && data->file[i][j + 1] == y
				&& data->file[i][j + 1] != '\0')
			{
				temp++;
			}
		}
	}
	if (temp != 1)
	{
		printf("Error\nInvalid number of textures\n");
		exit(1);
	}
}

void	check_number_texture(t_data *data)
{
	check_texture_map(data, 'N', 'O');
	check_texture_map(data, 'S', 'O');
	check_texture_map(data, 'E', 'A');
	check_texture_map(data, 'W', 'E');
}
