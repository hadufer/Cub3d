/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:46:51 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/31 16:11:15 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>
#include <stdlib.h>

void	draw_square(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int	i;
	int	j;

	i = a.x;
	j = a.y;
	while (i < b.x)
	{
		j = a.y;
		while (j < b.y)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->s_height)
	{
		j = 0;
		while (j < data->s_width)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_map_2d(t_data *data)
{
	int	xo;
	int	yo;
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			xo = x * MAPTILE / 4;
			yo = y * MAPTILE / 4;
			if (data->int_map[y * data->x + x] == 1)
				draw_square(data, new_vec2(xo + 1, yo + 1),
					new_vec2(xo + MAPTILE / 4 - 1, yo + MAPTILE / 4 - 1),
					0x00000000);
			else if (data->int_map[y * data->x + x] == 0)
				draw_square(data, new_vec2(xo + 1, yo + 1),
					new_vec2(xo + MAPTILE / 4 - 1, yo + MAPTILE / 4 - 1),
					0x00FFFFFF);
			x++;
		}
		y++;
	}
}

int	close_w(t_data *parsed)
{
	free_exit(parsed, 0, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*parsed;

	parsed = parse(argc, argv);
	map_get_ply_pos_fix(parsed);
	init_game(parsed);
	parsed->tex_n = load_image(parsed, parsed->path_to_north);
	parsed->tex_s = load_image(parsed, parsed->path_to_south);
	parsed->tex_e = load_image(parsed, parsed->path_to_east);
	parsed->tex_w = load_image(parsed, parsed->path_to_west);
	mlx_hook((*parsed).win, 2, 1L << 0, (void *)key_handler, parsed);
	mlx_hook(parsed->win, 17, 0, close_w, parsed);
	mlx_loop_hook((*parsed).mlx, render, parsed);
	mlx_loop((*parsed).mlx);
}
