/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:46:51 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/13 17:23:32 by hadufer          ###   ########.fr       */
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

void plotLineWidth(t_data *data, int x0, int y0, int x1, int y1, float wd, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx - dy, e2, x2, y2; /* error value e_xy */
	float ed = dx + dy == 0 ? 1 : sqrt((float)dx * dx + (float)dy * dy);

	for (wd = (wd + 1) / 2;;)
	{ /* pixel loop */
		my_mlx_pixel_put(data, x0, y0, color);
		e2 = err;
		x2 = x0;
		if (2 * e2 >= -dx)
		{ /* x step */
			for (e2 += dy, y2 = y0; e2 < ed * wd && (y1 != y2 || dx > dy); e2 += dx)
				my_mlx_pixel_put(data, x0, y2 += sy, color);
			if (x0 == x1)
				break;
			e2 = err;
			err -= dy;
			x0 += sx;
		}
		if (2 * e2 <= dy)
		{ /* y step */
			for (e2 = dx - e2; e2 < ed * wd && (x1 != x2 || dx < dy); e2 += dy)
				my_mlx_pixel_put(data, x2 += sx, y0, color);
			if (y0 == y1)
				break;
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_horizontal_ray(t_data *data)
{
	int		r,mx,my,mp,dof;
	float	rx,ry,ra,xo,yo;
	
	ra = data->ply.a;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		float	aTan = -1/tan(ra);
		if (ra > PI)
		{
			ry = (((int)data->ply.y >> 6) << 6)-0.0001;
			rx = (data->ply.y - ry) * aTan + data->ply.x;
			yo = -64;
			xo = -yo*aTan;
		}
		if (ra < PI)
		{
			ry = (((int)data->ply.y >> 6) << 6)+64;
			rx = (data->ply.y - ry) * aTan + data->ply.x;
			yo = 64;
			xo = -yo*aTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->ply.x;
			ry = data->ply.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * MapX + mx;
			if ((mp < MapX * MapY) && map[mp] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		plotLineWidth(data, data->ply.x, data->ply.y, rx, ry, 2.0, 0x0000FF00);
		r++;
	}
}

void	draw_vertical_ray(t_data *data)
{
	int		r,mx,my,mp,dof;
	float	rx,ry,ra,xo,yo;
	
	ra = data->ply.a;
	r = 0;
	while (r < 1)
	{
		dof = 0;
		float	nTan = -tan(ra);
		if (ra > P2 && ra < P3)
		{
			rx = (((int)data->ply.x >> 6) << 6)-0.0001;
			ry = (data->ply.x - rx) * nTan + data->ply.y;
			xo = -64;
			yo = -xo*nTan;
		}
		if (ra < P2 || ra > P3)
		{
			rx = (((int)data->ply.x >> 6) << 6)+64;
			ry = (data->ply.x - rx) * nTan + data->ply.y;
			xo = 64;
			yo = -xo*nTan;
		}
		if (ra == 0 || ra == PI)
		{
			rx = data->ply.x;
			ry = data->ply.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * MapX + mx;
			if ((mp < MapX * MapY) && map[mp] == 1)
				dof = 8;
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		plotLineWidth(data, data->ply.x, data->ply.y, rx, ry, 3.0, 0x00FF0000);
		r++;
	}
}

void	key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_W)
	{
		data->ply.y -= data->ply.dy;
		data->ply.x -= data->ply.dx;
	}
	else if (keycode == KEY_S)
	{
		data->ply.y += data->ply.dy;
		data->ply.x += data->ply.dx;
	}
	else if (keycode == KEY_A)
	{
		data->ply.y += sin(data->ply.a - PI/2) * 5;
		data->ply.x += cos(data->ply.a - PI/2) * 5;
	}
	else if (keycode == KEY_D)
	{
		data->ply.y += sin(data->ply.a + PI/2) * 5;
		data->ply.x += cos(data->ply.a + PI/2) * 5;
	}
	else if (keycode == KEY_LEFT)
	{
		data->ply.a -= 0.1;
		if (data->ply.a < 0)
			data->ply.a += PI * 2;
		data->ply.dx = cos(data->ply.a) * 5;
		data->ply.dy = sin(data->ply.a) * 5;
	}
	else if (keycode == KEY_RIGHT)
	{
		data->ply.a += 0.1;
		if (data->ply.a > (2 * PI))
			data->ply.a -= 2 * PI;
		data->ply.dx = cos(data->ply.a) * 5;
		data->ply.dy = sin(data->ply.a) * 5;
	}
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
	draw_vertical_ray(data);
	draw_horizontal_ray(data);
	// plotLineWidth(data, data->ply.x, data->ply.y, data->ply.x + data->ply.dx * 5, data->ply.y + data->ply.dy * 5, 2.0, 0xFFFF0000);
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
	data.ply.a = 45 * DR;
	data.ply.dx = cos(data.ply.a) * 5;
	data.ply.dy = sin(data.ply.a) * 5;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.s_width, data.s_height, "cub3d");
	data.img = mlx_new_image(data.mlx, data.s_width, data.s_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
			&data.endian);
	mlx_hook(data.win, 2, 1L << 0, (void *)key_handler, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
}
