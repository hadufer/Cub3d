/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:21:22 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/31 15:25:03 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

void	compute_draw_ray_vertical(t_data *data, int *tab, float *tabf)
{
	tab[4] = 0;
	tabf[6] = -tan(tabf[2]);
	data->ply.distv = 1000000;
	data->ply.vx = data->ply.x;
	data->ply.vy = data->ply.y;
	if (tabf[2] > p2f() && tabf[2] < p3f())
	{
		tabf[0] = (((int)data->ply.x >> 6) << 6) - 0.0001;
		tabf[1] = (data->ply.x - tabf[0]) * tabf[6] + data->ply.y;
		tabf[3] = -64;
		tabf[4] = -tabf[3] * tabf[6];
	}
	if (tabf[2] < p2f() || tabf[2] > p3f())
	{
		tabf[0] = (((int)data->ply.x >> 6) << 6) + 64;
		tabf[1] = (data->ply.x - tabf[0]) * tabf[6] + data->ply.y;
		tabf[3] = 64;
		tabf[4] = -tabf[3] * tabf[6];
	}
	if (tabf[2] == 0 || tabf[2] == PI)
	{
		tabf[0] = data->ply.x;
		tabf[1] = data->ply.y;
		tab[4] = data->x;
	}
}

void	compute_draw_ray_vertical2(t_data *data, int *tab, float *tabf)
{
	while (tab[4] < data->x)
	{
		tab[1] = (int)(tabf[0]) >> 6;
		tab[2] = (int)(tabf[1]) >> 6;
		tab[3] = tab[2] * data->x + tab[1];
		if ((tab[3] > 0) && (tab[3] < data->x * data->y)
			&& data->int_map[tab[3]] == 1)
		{
			data->ply.vx = tabf[0];
			data->ply.vy = tabf[1];
			data->ply.distv = dist_2d(data->ply.x,
					data->ply.y, data->ply.vx, data->ply.vy);
			tab[4] = data->x;
		}
		else
		{
			tabf[0] += tabf[3];
			tabf[1] += tabf[4];
			tab[4] += 1;
		}
	}
}

void	compute_draw_ray_horizontal(t_data *data, int *tab, float *tabf)
{
	tab[4] = 0;
	tabf[7] = -1 / tan(tabf[2]);
	data->ply.disth = 1000000;
	data->ply.hx = data->ply.x;
	data->ply.hy = data->ply.y;
	if (tabf[2] > PI)
	{
		tabf[1] = (((int)data->ply.y >> 6) << 6) - 0.0001;
		tabf[0] = (data->ply.y - tabf[1]) * tabf[7] + data->ply.x;
		tabf[4] = -64;
		tabf[3] = -tabf[4] * tabf[7];
	}
	if (tabf[2] < PI)
	{
		tabf[1] = (((int)data->ply.y >> 6) << 6) + 64;
		tabf[0] = (data->ply.y - tabf[1]) * tabf[7] + data->ply.x;
		tabf[4] = 64;
		tabf[3] = -tabf[4] * tabf[7];
	}
	if (tabf[2] == 0 || tabf[2] == PI)
	{
		tabf[0] = data->ply.x;
		tabf[1] = data->ply.y;
		tab[4] = data->y;
	}
}

void	compute_draw_ray_horizontal2(t_data *data, int *tab, float *tabf)
{
	while (tab[4] < data->y)
	{
		tab[1] = (int)(tabf[0]) >> 6;
		tab[2] = (int)(tabf[1]) >> 6;
		tab[3] = tab[2] * data->x + tab[1];
		if ((tab[3] > 0) && (tab[3] < data->x * data->y)
			&& data->int_map[tab[3]] == 1)
		{
			data->ply.hx = tabf[0];
			data->ply.hy = tabf[1];
			data->ply.disth = dist_2d(data->ply.x,
					data->ply.y, data->ply.hx, data->ply.hy);
			tab[4] = data->y;
		}
		else
		{
			tabf[0] += tabf[3];
			tabf[1] += tabf[4];
			tab[4] += 1;
		}
	}
}

void	compute_draw_ray_dist_init_line(t_data *data, int *tab, float *tabf)
{
	if (data->ply.distv < data->ply.disth)
	{
		tabf[0] = data->ply.vx;
		tabf[1] = data->ply.vy;
		tabf[5] = data->ply.distv;
	}
	if (data->ply.disth < data->ply.distv)
	{
		tabf[0] = data->ply.hx;
		tabf[1] = data->ply.hy;
		tabf[5] = data->ply.disth;
	}
	tabf[12] = data->ply.a - tabf[2];
	fix_angle(&tabf[12]);
	tabf[5] = tabf[5] * cos(tabf[12]);
	tab[7] = (MAPTILE * 500) / tabf[5];
	tabf[11] = 32.0 / (float)tab[7];
	tabf[10] = 0;
}
