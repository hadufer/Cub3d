/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:46:51 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/12 17:14:18 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>
#include <stdlib.h>

int MapX = 8, MapY = 8, MapTile = 64;
int map[]={
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,1,1,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,
};

void	draw_square(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	int	i;
	int	j;

	i = x0;
	j = y0;
	while (i < x1)
	{
		j = y0;
		while (j < y1)
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
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->ply.y += 1;
	else if (keycode == KEY_S)
		data->ply.y -= 1;
	else if (keycode == KEY_A)
		data->ply.x -= 1;
	else if (keycode == KEY_D)
		data->ply.x += 1;
	else if (keycode == KEY_ESCAPE)
		exit(0);
}

void	draw_map_2d(t_data *data)
{
	int	x, y, xo, yo;
	int	color;

	for (size_t y = 0; y < MapY; y++)
	{
		for (size_t x = 0; x < MapX; x++)
		{
			xo = x * MapTile;
			yo = y * MapTile;
			if (map[y * MapX+x] == 1)
				color = 0x00000000;
			else
				color = 0x00FFFFFF;
			draw_square(data, xo + 1, yo + 1, xo + MapTile - 1, yo + MapTile - 1, color);
		}
		
	}
	
}

void	Draw2d(t_data *data)
{
	draw_background(data, 0x696969);
	draw_map_2d(data);
	draw_square(data, data->ply.x, data->ply.y, data->ply.x + 5, data->ply.y + 5, 0xFFD700);
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->s_width, data->s_height);
	Draw2d(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.s_height = 800;
	data.s_width = 800;
	data.ply.x = 250;
	data.ply.y = 250;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.s_width, data.s_height, "cub3d");
	data.img = mlx_new_image(data.mlx, data.s_width, data.s_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
			&data.endian);
	mlx_hook(data.win, 2, 1L << 0, (void *)key_handler, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
