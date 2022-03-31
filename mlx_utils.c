/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:02:01 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/31 13:07:02 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || x > data->s_width) || (y < 0 || y > data->s_height))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	*load_image_malloc(t_data *data, int *tab, int *xpm_data)
{
	int		*tex;

	tex = malloc(sizeof(int)
			* (data->img_xpm_height * data->img_xpm_width + 1));
	while (tab[3] < data->img_xpm_height)
	{
		tab[4] = 0;
		while (tab[4] < data->img_xpm_width)
		{
			tex[data->img_xpm_width * tab[3] + tab[4]]
				= xpm_data[data->img_xpm_width * tab[3] + tab[4]];
			tab[4]++;
		}
		tab[3]++;
	}
	return (tex);
}

// Load image and put it into texture
int	*load_image(t_data *data, char *path)
{
	int		*tex;
	void	*img_xpm;
	int		*xpm_data;
	int		tab[5];

	tab[3] = 0;
	tab[0] = data->bits_per_pixel;
	tab[1] = data->line_length;
	tab[2] = data->endian;
	img_xpm = mlx_xpm_file_to_image(data->mlx, path,
			&data->img_xpm_width, &data->img_xpm_height);
	if (!img_xpm)
		free_exit(data, 1, "Error while loading texture");
	xpm_data = (int *)mlx_get_data_addr(img_xpm,
			&tab[0], &tab[1], &tab[2]);
	tex = load_image_malloc(data, tab, xpm_data);
	mlx_destroy_image(data->mlx, img_xpm);
	return (tex);
}
