/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:47:03 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/12 13:56:13 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define KEY_ESCAPE 53
# define KEY_S 13
# define KEY_A 0
# define KEY_W 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
# include <mlx.h>

typedef struct s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct s_player
{
	int			x;
	int			y;

}				t_player;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			s_width;
	int			s_height;
	t_player	ply;
}				t_data;

// UTILS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_data *data, t_vec2 a, t_vec2 b, int color);
#endif