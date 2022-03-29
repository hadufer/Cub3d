/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:47:03 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/29 15:59:50 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define PI 3.14159265359
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.01745329252
# define KEY_ESCAPE 53
# define KEY_S 1
# define KEY_A 0
# define KEY_W 13
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define MAPTILE 64
# define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
# include <mlx.h>
# include "cube.h"
# include "parsing.h"

typedef struct s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_player
{
	int			x;
	int			y;
	float		a;
	float		dx;
	float		dy;

	// raycast
	float		distH;
	float		hx;
	float		hy;
	float		distV;
	float		vx;
	float		vy;
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
	int			*texN;
	int			*texS;
	int			*texE;
	int			*texW;
	char		*path_to_north;
	t_color		north_texture;
	char		*path_to_south;
	t_color		south_texture;
	char		*path_to_east;
	t_color		east_texture;
	char		*path_to_west;
	t_color		west_texture;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	char		**file;
	int			*int_map;
	int			x;
	int			y;
	t_player	ply;
	int			ply_x;
	int			ply_y;
	char	player_direction;
}				t_data;

// UTILS
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	draw_line(t_data *data, t_vec2 a, t_vec2 b, int color);
t_vec2	new_vec2(float x, float y);
#endif