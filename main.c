/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:46:51 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/17 13:38:28 by hadufer          ###   ########.fr       */
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
			my_mlx_pixel_put(data, j, i, color);
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

float	dist_2d(float x0, float y0, float x1, float y1, float ang)
{
	return (sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)));
}

void	compute_draw_ray(t_data *data)
{
	int		r,mx,my,mp,dof;
	float	rx,ry,ra,xo,yo,distT;
	
	// Vertical ray collide with wall
	ra = data->ply.a - DR * 30;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	r = 0;
	while (r < 60 * 2)
	{
		dof = 0;
		float	nTan = -tan(ra);
		data->ply.distV = 1000000;
		data->ply.vx = data->ply.x;
		data->ply.vy = data->ply.y;
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
			if ((mp > 0) && (mp < MapX * MapY) && map[mp] == 1)
			{
				data->ply.vx = rx;
				data->ply.vy = ry;
				data->ply.distV = dist_2d(data->ply.x, data->ply.y, data->ply.vx, data->ply.vy, data->ply.a);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		// Horizontal ray collide with wall
		dof = 0;
		float	aTan = -1/tan(ra);
		data->ply.distH = 1000000;
		data->ply.hx = data->ply.x;
		data->ply.hy = data->ply.y;
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
			if ((mp > 0) && (mp < MapX * MapY) && map[mp] == 1)
			{
				data->ply.hx = rx;
				data->ply.hy = ry;
				data->ply.distH = dist_2d(data->ply.x, data->ply.y, data->ply.hx, data->ply.hy, data->ply.a);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		int color;
		if (data->ply.distV < data->ply.distH)
		{
			rx = data->ply.vx;
			ry = data->ply.vy;
			distT = data->ply.distV;
			color = 0x00FF0000; // red
		}
		if (data->ply.distH < data->ply.distV)
		{
			rx = data->ply.hx;
			ry = data->ply.hy;
			distT = data->ply.distH;
			color = 0x008B0000; // green
		}
		float ca = data->ply.a - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		distT = distT * cos(ca);
		float lineH = (MapTile * 320)/distT;
		if (lineH > 320)
			lineH = 320;
		float lineO = 160 - lineH/2;
		plotLineWidth(data, data->ply.x, data->ply.y, rx, ry, 1.0, 0x00FF0000); // ray 2d
		draw_square(data, r * 4 + MapTile * 8, lineO, r * 4 + MapTile * 8 + 4, lineH + lineO, color);
		r++;
		ra += DR / 2;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}

void	key_handler(int keycode, t_data *data)
{
	if (keycode == KEY_W)
	{
		data->ply.x -= round(data->ply.dx);
		data->ply.y -= round(data->ply.dy);
	}
	else if (keycode == KEY_S)
	{
		data->ply.x += round(data->ply.dx);
		data->ply.y += round(data->ply.dy);
	}
	else if (keycode == KEY_A)
	{
		data->ply.x += round(cos(data->ply.a - P2) * 5);
		data->ply.y += round(sin(data->ply.a - P2) * 5);
	}
	else if (keycode == KEY_D)
	{
		data->ply.x += round(cos(data->ply.a + P2) * 5);
		data->ply.y += round(sin(data->ply.a + P2) * 5);
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
	compute_draw_ray(data);
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

	data.s_height = 1000;
	data.s_width = 1500;
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
