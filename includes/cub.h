/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nferre <nferre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 10:47:03 by hadufer           #+#    #+#             */
/*   Updated: 2022/03/30 10:59:55 by nferre           ###   ########.fr       */
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
	float		disth;
	float		hx;
	float		hy;
	float		distv;
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
	int			*tex_n;
	int			*tex_s;
	int			*tex_e;
	int			*tex_w;
	int			img_xpm_width;
	int			img_xpm_height;
	char		*path_to_north;
	char		*path_to_south;
	char		*path_to_east;
	char		*path_to_west;
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
	char		player_direction;
}					t_data;

void	draw2d(t_data *data);
int		render(t_data *data);
void	init_player_direction(t_data *parsed);
void	compute_draw_ray(t_data *data);
void	draw_map_2d(t_data *data);
void	draw_background(t_data *data, int color);
void	draw_square(t_data *data, t_vec2 a, t_vec2 b, int color);
// UTILS
void	plotLineWidth(t_data *data, int x0, int y0, int x1, int y1, float wd, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	draw_line(t_data *data, t_vec2 a, t_vec2 b, int color);
t_vec2	new_vec2(float x, float y);
int		t_color_to_int(t_color col);
float	dist_2d(float x0, float y0, float x1, float y1);
#endif