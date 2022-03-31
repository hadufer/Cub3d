/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:36:16 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/31 15:23:35 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

void	compute_draw_ray_tex(t_data *data, int *tab, float *tabf)
{
	while (tab[6] < tab[7])
	{
		if ((tabf[2] < p2f() || tabf[2] > p3f())
			&& data->ply.distv < data->ply.disth)
			tab[8] = *(int *)(data->tex_e + (int)tabf[8] * 32 + (int)(tabf[9]));
		else if ((tabf[2] > p2f() && tabf[2] < p3f())
			&& data->ply.distv < data->ply.disth)
			tab[8] = *(int *)(data->tex_w + (int)tabf[8] * 32 + (int)(tabf[9]));
		else if ((tabf[2] > 0 && tabf[2] < PI)
			&& data->ply.distv > data->ply.disth)
			tab[8] = *(int *)(data->tex_s + (int)tabf[8] * 32 + (int)(tabf[9]));
		else
			tab[8] = *(int *)(data->tex_n + (int)tabf[8] * 32 + (int)(tabf[9]));
		if (tab[6] + tab[5] + 3 <= data->s_height)
			draw_square(data, new_vec2(tab[0] * 3, tab[6] + tab[5]),
				new_vec2(tab[0] * 3 + 3, tab[6] + tab[5] + 3), tab[8]);
		tabf[8] += tabf[11];
		tab[6]++;
	}
}

void	compute_draw_ray_init_line_arg(t_data *data, int *tab, float *tabf)
{
	if (tab[7] > 500)
	{
		tabf[10] = (tab[7] - 500) / 2.0;
		tab[7] = 500;
	}
	tab[5] = 250 - (tab[7] >> 1);
	tab[6] = 0;
	tabf[8] = tabf[10] * tabf[11];
	if (data->ply.distv < data->ply.disth)
	{
		tabf[9] = (int)(tabf[1] / 2.0) % 32;
		tabf[9] = 31 - tabf[9];
	}
	else
	{
		tabf[9] = (int)(tabf[0] / 2.0) % 32;
		tabf[9] = 31 - tabf[9];
	}
}

void	compute_draw_ray(t_data *data)
{
	int		tab[9];
	float	tabf[14];

	tabf[2] = data->ply.a - DR * 30;
	fix_angle(&tabf[2]);
	tab[0] = 0;
	while (tab[0] < 60 * 4)
	{
		compute_draw_ray_vertical(data, tab, tabf);
		compute_draw_ray_vertical2(data, tab, tabf);
		compute_draw_ray_horizontal(data, tab, tabf);
		compute_draw_ray_horizontal2(data, tab, tabf);
		compute_draw_ray_dist_init_line(data, tab, tabf);
		compute_draw_ray_init_line_arg(data, tab, tabf);
		compute_draw_ray_tex(data, tab, tabf);
		tab[0]++;
		tabf[2] += DR / 4;
		fix_angle(&tabf[2]);
	}
}
