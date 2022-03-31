/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:37:54 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/31 13:51:25 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

void	key_a_handle(int keycode, t_data *data, int *tab)
{
	if (keycode == KEY_A)
	{
		if ((cos(data->ply.a - p2f()) * 5) < 0)
			tab[6] = -20;
		else
			tab[6] = 20;
		if ((sin(data->ply.a - p2f()) * 5) < 0)
			tab[7] = -20;
		else
			tab[7] = 20;
		tab[4] = (data->ply.y + tab[7]) >> 6;
		tab[2] = (data->ply.x + tab[6]) >> 6;
		tab[5] = (data->ply.y - tab[7]) >> 6;
		tab[3] = (data->ply.x - tab[6]) >> 6;
		if (data->int_map[tab[1] * data->x + tab[2]] == 0)
			data->ply.x += round(cos(data->ply.a - p2f()) * 5);
		if (data->int_map[tab[4] * data->x + tab[0]] == 0)
			data->ply.y += round(sin(data->ply.a - p2f()) * 5);
	}
}

void	key_d_handle(int keycode, t_data *data, int *tab)
{
	if (keycode == KEY_D)
	{
		if ((cos(data->ply.a - p2f()) * 5) < 0)
			tab[6] = -20;
		else
			tab[6] = 20;
		if ((sin(data->ply.a - p2f()) * 5) < 0)
			tab[7] = -20;
		else
			tab[7] = 20;
		tab[4] = (data->ply.y + tab[7]) >> 6;
		tab[2] = (data->ply.x + tab[6]) >> 6;
		tab[5] = (data->ply.y - tab[7]) >> 6;
		tab[3] = (data->ply.x - tab[6]) >> 6;
		if (data->int_map[tab[1] * data->x + tab[3]] == 0)
			data->ply.x += round(cos(data->ply.a + p2f()) * 5);
		if (data->int_map[tab[5] * data->x + tab[0]] == 0)
			data->ply.y += round(sin(data->ply.a + p2f()) * 5);
	}
}

void	key_ws_handle(int keycode, t_data *data, int *tab)
{
	if (keycode == KEY_W)
	{
		if (data->int_map[tab[1] * data->x + tab[2]] == 0)
			data->ply.x += data->ply.dx;
		if (data->int_map[tab[4] * data->x + tab[0]] == 0)
			data->ply.y += data->ply.dy;
	}
	if (keycode == KEY_S)
	{
		if (data->int_map[tab[1] * data->x + tab[3]] == 0)
			data->ply.x -= data->ply.dx;
		if (data->int_map[tab[5] * data->x + tab[0]] == 0)
			data->ply.y -= data->ply.dy;
	}
}

void	key_left_right_esc_handle(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
	{
		data->ply.a -= 0.1;
		if (data->ply.a < 0)
			data->ply.a += PI * 2;
		data->ply.dx = cos(data->ply.a) * 5;
		data->ply.dy = sin(data->ply.a) * 5;
	}
	if (keycode == KEY_RIGHT)
	{
		data->ply.a += 0.1;
		if (data->ply.a > (2 * PI))
			data->ply.a -= 2 * PI;
		data->ply.dx = cos(data->ply.a) * 5;
		data->ply.dy = sin(data->ply.a) * 5;
	}
	if (keycode == KEY_ESCAPE)
		free_exit(data, 0, NULL);
}

void	key_handler(int keycode, t_data *data)
{
	int	tab[8];

	tab[6] = 0;
	tab[7] = 0;
	if (data->ply.dx < 0)
		tab[6] = -20;
	else
		tab[6] = 20;
	if (data->ply.dy < 0)
		tab[7] = -20;
	else
		tab[7] = 20;
	tab[0] = data->ply.x >> 6;
	tab[2] = (data->ply.x + tab[6]) >> 6;
	tab[3] = (data->ply.x - tab[6]) >> 6;
	tab[1] = data->ply.y >> 6;
	tab[4] = (data->ply.y + tab[7]) >> 6;
	tab[5] = (data->ply.y - tab[7]) >> 6;
	key_ws_handle(keycode, data, tab);
	key_a_handle(keycode, data, tab);
	key_d_handle(keycode, data, tab);
	key_left_right_esc_handle(keycode, data);
}
