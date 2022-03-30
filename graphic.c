/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:16:35 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/30 19:42:06 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw2d(t_data *data)
{
	draw_background(data, 0x696969);
	draw_square(data, new_vec2(0, data->s_height / 2),
		new_vec2(data->s_width, data->s_height),
		t_color_to_int(data->ceiling_color));
	draw_square(data, new_vec2(0, 0),
		new_vec2(data->s_width, data->s_height / 2),
		t_color_to_int(data->floor_color));
	compute_draw_ray(data);
	draw_map_2d(data);
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->s_width, data->s_height);
	draw2d(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
