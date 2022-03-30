/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:25:04 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/30 19:37:16 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

void	map_get_ply_pos_fix(t_data *parsed)
{
	int	i;
	int	j;

	i = 0;
	while (i < parsed->y)
	{
		j = 0;
		while (j < parsed->x)
		{
			if (parsed->int_map[i * parsed->x + j] == 2)
			{
				parsed->ply_x = j;
				parsed->ply_y = i;
				parsed->int_map[i * parsed->x + j] = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_game(t_data *parsed)
{
	parsed->s_height = 500;
	parsed->s_width = 720;
	parsed->ply.x = parsed->ply_x * MAPTILE + MAPTILE / 2;
	parsed->ply.y = parsed->ply_y * MAPTILE + MAPTILE / 2;
	init_player_direction(parsed);
	parsed->ply.dx = cos((*parsed).ply.a) * 5;
	parsed->ply.dy = sin((*parsed).ply.a) * 5;
	parsed->mlx = mlx_init();
	parsed->win = mlx_new_window((*parsed).mlx,
			(*parsed).s_width, (*parsed).s_height, "cub3d");
	parsed->img = mlx_new_image((*parsed).mlx,
			(*parsed).s_width, (*parsed).s_height);
	parsed->addr = mlx_get_data_addr((*parsed).img,
			&parsed->bits_per_pixel, &parsed->line_length,
			&parsed->endian);
}

void	init_player_direction(t_data *parsed)
{
	if (parsed->player_direction == 'N')
		parsed->ply.a = P3;
	else if (parsed->player_direction == 'S')
		parsed->ply.a = P2;
	else if (parsed->player_direction == 'W')
		parsed->ply.a = PI;
	else if (parsed->player_direction == 'O')
		parsed->ply.a = 0;
}

void	free_exit(t_data *parsed, int code, char *print_msg_newline)
{
	int	i;

	i = 0;
	free(parsed->file);
	while (parsed->map[i])
	{
		free(parsed->map[i]);
		i++;
	}
	free(parsed->map);
	free(parsed->int_map);
	free(parsed->path_to_east);
	free(parsed->path_to_west);
	free(parsed->path_to_north);
	free(parsed->path_to_south);
	if (parsed->tex_e)
		free(parsed->tex_e);
	if (parsed->tex_w)
		free(parsed->tex_w);
	if (parsed->tex_s)
		free(parsed->tex_s);
	if (parsed->tex_n)
		free(parsed->tex_n);
	if (print_msg_newline)
		printf("%s\n", print_msg_newline);
	while (1)
	{}
	exit(code);
}
