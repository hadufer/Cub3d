/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:46:51 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/30 19:39:09 by hadufer          ###   ########.fr       */
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

void	plotLineWidth(t_data *data, int x0, int y0, int x1, int y1, float wd, int color)
{
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx - dy, e2, x2, y2;
	float ed = dx + dy == 0 ? 1 : sqrt((float)dx * dx + (float)dy * dy);

	for (wd = (wd + 1) / 2;;)
	{
		my_mlx_pixel_put(data, x0, y0, color);
		e2 = err;
		x2 = x0;
		if (2 * e2 >= -dx)
		{
			for (e2 += dy, y2 = y0; e2 < ed * wd && (y1 != y2 || dx > dy); e2 += dx)
				my_mlx_pixel_put(data, x0, y2 += sy, color);
			if (x0 == x1)
				break;
			e2 = err;
			err -= dy;
			x0 += sx;
		}
		if (2 * e2 <= dy)
		{
			for (e2 = dx - e2; e2 < ed * wd && (x1 != x2 || dx < dy); e2 += dy)
				my_mlx_pixel_put(data, x2 += sx, y0, color);
			if (y0 == y1)
				break;
			err += dx;
			y0 += sy;
		}
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
	while (r < 60 * 4)
	{
		dof = 0;
		float	nTan = -tan(ra);
		data->ply.distv = 1000000;
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
			dof = data->x;
		}
		while (dof < data->x)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * data->x + mx;
			if ((mp > 0) && (mp < data->x * data->y) && data->int_map[mp] == 1)
			{
				data->ply.vx = rx;
				data->ply.vy = ry;
				data->ply.distv = dist_2d(data->ply.x, data->ply.y, data->ply.vx, data->ply.vy);
				dof = data->x;
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
		data->ply.disth = 1000000;
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
			dof = data->y;
		}
		while (dof < data->y)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			mp = my * data->x + mx;
			if ((mp > 0) && (mp < data->x * data->y) && data->int_map[mp] == 1)
			{
				data->ply.hx = rx;
				data->ply.hy = ry;
				data->ply.disth = dist_2d(data->ply.x, data->ply.y, data->ply.hx, data->ply.hy);
				dof = data->y;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		if (data->ply.distv < data->ply.disth)
		{
			rx = data->ply.vx;
			ry = data->ply.vy;
			distT = data->ply.distv;
		}
		if (data->ply.disth < data->ply.distv)
		{
			rx = data->ply.hx;
			ry = data->ply.hy;
			distT = data->ply.disth;
		}
		float ca = data->ply.a - ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		distT = distT * cos(ca);
		int lineH = (MAPTILE * 500)/distT;
		float ty_step = 32.0/(float)lineH;
		float ty_off = 0;
		if (lineH > 500)
		{
			ty_off = (lineH - 500)/2.0;
			lineH = 500;
		}
		int lineO = 250 - (lineH >> 1);
		plotLineWidth(data, data->ply.x / 4, data->ply.y / 4, rx / 4, ry / 4, 1.0, 0x00FF0000); // ray 2d
		int y = 0;
		float ty = ty_off * ty_step;
		float tx;
		if (data->ply.distv < data->ply.disth)
		{
			tx = (int)(ry/2.0)%32;
			tx = 31 - tx;
		}
		else
		{
			tx = (int)(rx/2.0)%32;
			tx = 31 - tx;
		}
		while (y < lineH)
		{
			int tex;
			if ((ra < P2 || ra > P3) && data->ply.distv < data->ply.disth)
				tex = *(int *)(data->tex_e + (int)ty * 32 + (int)(tx));
			else if ((ra > P2 && ra < P3) && data->ply.distv < data->ply.disth)
				tex = *(int *)(data->tex_w + (int)ty * 32 + (int)(tx));
			else if ((ra > 0 && ra < PI) && data->ply.distv > data->ply.disth)
				tex = *(int *)(data->tex_s + (int)ty * 32 + (int)(tx));
			else
				tex = *(int *)(data->tex_n + (int)ty * 32 + (int)(tx));
			if (y + lineO + 3 <= data->s_height)
				draw_square(data, new_vec2(r * 3, y + lineO),
					new_vec2(r * 3 + 3, y + lineO + 3), tex);
			ty += ty_step;
			y++;
		}
		r++;
		ra += DR / 4;
		if (ra < 0)
			ra += 2 * PI;
		if (ra > 2 * PI)
			ra -= 2 * PI;
	}
}

void	key_handler(int keycode, t_data *data)
{
	int xo = 0;
	int yo = 0;
	if (data->ply.dx < 0)
		xo = -20;
	else
		xo = 20;
	if (data->ply.dy < 0)
		yo = -20;
	else
		yo = 20;
	int ipx=data->ply.x >> 6;
	int ipx_add_xo=(data->ply.x+xo) >> 6;
	int ipx_sub_xo=(data->ply.x-xo) >> 6;
	int ipy=data->ply.y >> 6;
	int ipy_add_yo=(data->ply.y+yo) >> 6;
	int ipy_sub_yo=(data->ply.y-yo) >> 6;
	if (keycode == KEY_W)
	{
		if(data->int_map[ipy * data->x + ipx_add_xo] == 0)
			data->ply.x += data->ply.dx;
		if(data->int_map[ipy_add_yo * data->x + ipx] == 0)
			data->ply.y += data->ply.dy;
	}
	else if (keycode == KEY_S)
	{
		if(data->int_map[ipy * data->x + ipx_sub_xo] == 0)
			data->ply.x -= data->ply.dx;
		if(data->int_map[ipy_sub_yo * data->x + ipx] == 0)
			data->ply.y -= data->ply.dy;
	}
	else if (keycode == KEY_A)
	{
		if ((cos(data->ply.a - P2) * 5) < 0)
			xo = -20;
		else
			xo = 20;
		if ((sin(data->ply.a - P2) * 5) < 0)
			yo = -20;
		else
			yo = 20;
		ipy_add_yo=(data->ply.y+yo) >> 6;
		ipx_add_xo=(data->ply.x+xo) >> 6;
		ipy_sub_yo=(data->ply.y-yo) >> 6;
		ipx_sub_xo=(data->ply.x-xo) >> 6;
		if(data->int_map[ipy * data->x + ipx_add_xo] == 0)
			data->ply.x += round(cos(data->ply.a - P2) * 5);
		if(data->int_map[ipy_add_yo * data->x + ipx] == 0)
			data->ply.y += round(sin(data->ply.a - P2) * 5);
	}
	else if (keycode == KEY_D)
	{
		if ((cos(data->ply.a - P2) * 5) < 0)
			xo = -20;
		else
			xo = 20;
		if ((sin(data->ply.a - P2) * 5) < 0)
			yo = -20;
		else
			yo = 20;
		ipy_add_yo=(data->ply.y+yo) >> 6;
		ipx_add_xo=(data->ply.x+xo) >> 6;
		ipy_sub_yo=(data->ply.y-yo) >> 6;
		ipx_sub_xo=(data->ply.x-xo) >> 6;
		if(data->int_map[ipy * data->x + ipx_sub_xo] == 0)
			data->ply.x += round(cos(data->ply.a + P2) * 5);
		if(data->int_map[ipy_sub_yo * data->x + ipx] == 0)
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
		free_exit(data, 0, NULL);
}

// Load image and put it into texture
int	*load_image(t_data *data, char *path)
{
	int		*tex;
	int		tmp_bpp;
	int		tmp_ll;
	int		tmp_endian;
	void	*img_xpm;
	int		*xpm_data;
	int		y;
	int		x;

	y = 0;
	tmp_bpp = data->bits_per_pixel;
	tmp_ll = data->line_length;
	tmp_endian = data->endian;
	img_xpm = mlx_xpm_file_to_image(data->mlx, path,
				&data->img_xpm_width, &data->img_xpm_height);
	if (!img_xpm)
		free_exit(data, 1, "Error while loading texture");
	xpm_data = (int *)mlx_get_data_addr(img_xpm,
				&tmp_bpp, &tmp_ll, &tmp_endian);
	tex = malloc(sizeof(int) * (data->img_xpm_height * data->img_xpm_width + 1));
	while (y < data->img_xpm_height)
	{
		x = 0;
		while (x < data->img_xpm_width)
		{
			tex[data->img_xpm_width * y + x]
			= xpm_data[data->img_xpm_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img_xpm);
	return (tex);
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
	mlx_loop_hook((*parsed).mlx, render, parsed);
	mlx_loop((*parsed).mlx);
}
